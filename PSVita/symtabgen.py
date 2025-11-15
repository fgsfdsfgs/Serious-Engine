#!/usr/bin/env python3

import os
import sys
import subprocess
from pathlib import Path

if len(sys.argv) < 2:
    print("usage: " + sys.argv[0] + " <libfile>")
    sys.exit(1)

libfname = sys.argv[1];
libname = Path(libfname).resolve().stem
if libname.startswith("lib"):
    libname = libname[3:]

out = subprocess.run(['arm-vita-eabi-nm', libfname, '--demangle', '--defined', '--extern'], stdout=subprocess.PIPE).stdout.decode('utf-8')

exports = []
definitions = []

if "Entities" in libname:
    for line in out.splitlines():
        if line.endswith("_DLLClass"):
            name = line.split()[-1]
            exports.append(name)
            definitions.append('extern "C" CDLLEntityClass ' + name + ';')
elif "Game" in libname:
    exports.append("GAME_Create")
    definitions.append('extern "C" CGame *GAME_Create(void);')
elif "Shader" in libname:
    for line in out.splitlines():
        line = line.strip()
        if line == '': continue
        line = line.split()[-1]
        if line.startswith("Shader_Desc_"):
            exports.append(line)
            definitions.append('extern "C" void ' + line + '(ShaderDesc &shDesc);')
        elif line.startswith("Shader_"):
            exports.append(line)
            definitions.append('extern "C" void ' + line + '(void);')

exports = set(exports)
definitions = set(definitions)

print("#include <Engine/Base/NX/FakeExports.h>")

if "Entities" in libname:
    print('class CDLLEntityClass;')
elif "Game" in libname:
    print('class CGame;')
elif "Shader" in libname:
    print('struct ShaderDesc;')

print()
print("/* defs */")
print()

for d in definitions:
    print(d)

print()
print("/* exports */")
print()

print('static CFakeLib exp_{}("{}", {{'.format(libname, libname))

for e in exports:
    print('  {{ "{}", (void*)&{} }}, '.format(e, e))

print('});')

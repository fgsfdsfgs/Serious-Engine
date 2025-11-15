#!/bin/bash

BASEDIR=$(dirname "$0")
let NCPU=8
echo "Will build with 'make -j$NCPU' ... please edit this script if incorrect."

rm -rf psvita-build
mkdir $_
cd $_

# IMPORTANT: run another build script first to at least get a ecc binary for your host platform

cmake -G"Unix Makefiles" \
  -DCMAKE_TOOLCHAIN_FILE="$VITASDK/share/vita.toolchain.cmake" \
  -DCMAKE_BUILD_TYPE=RelWithDebInfo \
  -DPKG_CONFIG_EXECUTABLE="$VITASDK/bin/arm-vita-eabi-pkg-config" \
  -DECC="$BASEDIR/cmake-build/Ecc/ecc" \
  -DTFE=OFF \
  $1 \
  ..

make -j$NCPU -Oline

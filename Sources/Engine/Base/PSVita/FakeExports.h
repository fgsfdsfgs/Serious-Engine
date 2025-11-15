#ifndef SE_INCL_FAKEEXPORTS_H
#define SE_INCL_FAKEEXPORTS_H
#ifdef PRAGMA_ONCE
  #pragma once
#endif

#include <vector>
#include <string>
#include <initializer_list>

class CFakeLib
{
public:
    using SymPair = std::pair<std::string const, void*>;
    CFakeLib(const char *libname, std::initializer_list<SymPair> syms);
    void AddExport(const char *sym, void *val);
    void *GetExport(const char *sym);

private:
    const char *name;
    std::vector<SymPair> symtab;
};

class CFakeExportRegistry
{
public:
    using LibPair = std::pair<std::string const, CFakeLib *>;
    static CFakeLib *GetLib(const char *libname);
    static void AddLib(const char *libname, CFakeLib *lib);

private:
    static std::vector<LibPair> libmap;
};

#endif // SE_INCL_FAKEEXPORTS_H

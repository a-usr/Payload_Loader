#pragma once
#ifndef DIR_H
#define DIR_H
#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include "boost/filesystem.hpp"


int DeleteDirectory(const std::string& refcstrRootDirectory,
    bool              bDeleteSubdirectories = true)
{
    if (bDeleteSubdirectories) {
        boost::filesystem::remove_all(refcstrRootDirectory);
        return 0;
    }
    else{
        boost::filesystem::remove(refcstrRootDirectory);
        return 0;
    }
}
std::wstring ExePath() {
    TCHAR buffer[MAX_PATH] = { 0 };
    GetModuleFileName(NULL, buffer, MAX_PATH);
    std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
    return std::wstring(buffer).substr(0, pos);
}
void Copyfile(std::string src, std::string dst) {
    boost::filesystem::copy_file(src, dst);
}
std::vector<unsigned char> ReadBinary(std::string path) {
    std::ifstream file(path, std::ios::binary);
    std::vector<unsigned char> out(std::istreambuf_iterator<char>(file), {});
    file.close();
    return out;
}
void WriteBinary(std::string path, std::vector<unsigned char> vector) {
    std::ofstream file(path, std::ios::binary);
    std::cout << "Opened Output File..." << std::endl;
    file.write((char*)&vector[0], vector.size() * sizeof(unsigned char));
    file.close();
}
#endif
#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#ifndef GETREG_H
#define GETREG_H
#include <Windows.h>
#include <winreg.h>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
#include <codecvt>
#include <cstdlib>
#include "converter.hpp"
using namespace std;
void err(LONG code) {
	fstream out;
	out.open("log.txt");
	out << code;
	out << "\n";
}
std::vector<wstring> RegGetString(
	HKEY hKey,
	const std::wstring& subKey,
	const std::wstring& value
)
{
	DWORD dataSize{};
	LONG retCode = ::RegGetValueW(
		hKey,
		subKey.c_str(),
		value.c_str(),
		RRF_RT_REG_SZ,
		nullptr,
		nullptr,
		&dataSize
	);
	if (retCode != ERROR_SUCCESS)
	{
		err(retCode);
	}
	std::wstring data;
	data.resize(dataSize / sizeof(wchar_t));
	retCode = ::RegGetValueW(
		hKey,
		subKey.c_str(),
		value.c_str(),
		RRF_RT_REG_SZ,
		nullptr,
		&data[0],
		&dataSize
	);
	if (retCode != ERROR_SUCCESS)
	{
		err(retCode);
	}
	data.resize(dataSize / sizeof(wchar_t));
	std::vector<wstring> result;
	const wchar_t* currStringPtr = &data[0];
	while (*currStringPtr != L'\0')
	{
		const size_t currStringLength = wcslen(currStringPtr);
		result.push_back(std::wstring{ currStringPtr, currStringLength });
		currStringPtr += currStringLength + 1;
	}
	return result;
}
void DeleteValue(HKEY hkey, const wstring subkey, const wstring value)
{
	HKEY key;
	RegOpenKeyExW(hkey, subkey.c_str(), 0, KEY_SET_VALUE, &key);
	LONG retCode = RegDeleteValueW(key, value.c_str());
	if (retCode != ERROR_SUCCESS)
	{
		err(retCode);
	}
	RegCloseKey(key);
}
#endif
#pragma once
#pragma warning(disable : 4996)
#ifndef CONVERTER_H
#define CONVERTER_H
#include <vector>
#include <locale>
#include <codecvt>
using namespace std;
std::wstring wstring_convert_from_bytes(const std::vector< char >& v)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
	return converter.from_bytes(v.data(), v.data() + v.size());
}
std::wstring wstring_convert_from_char(const char* str)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
	return converter.from_bytes(str);
}
char *wstring_convert_to_char(wstring wStr)
{
	const wchar_t* input = wStr.c_str();

	// Count required buffer size (plus one for null-terminator).
	size_t size = (wcslen(input) + 1) * sizeof(wchar_t);
	char* buffer = new char[size];

#ifdef __STDC_LIB_EXT1__
	// wcstombs_s is only guaranteed to be available if __STDC_LIB_EXT1__ is defined
	size_t convertedSize;
	std::wcstombs_s(&convertedSize, buffer, size, input, size);
#else
	std::wcstombs(buffer, input, size);
#endif
	/* Use the string stored in "buffer" variable */
	return buffer;
	// Free allocated memory:
	delete[] buffer;
}
string wstring_convert_to_string(wstring wstr)
{
	using convert_type = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_type, wchar_t> converter;

	//use converter (.to_bytes: wstr->str, .from_bytes: str->wstr)
	std::string result = converter.to_bytes(wstr);
	return result;
}
string Unsign_charray_to_string(unsigned char In[]) {
    string out = reinterpret_cast<char *>(In);
    return out;
}
vector<unsigned char> Unsign_charray_to_vec(unsigned char in[]) {
    return vector<unsigned char>(in, in + sizeof(in));
}
char const * pad(std::string str, const int val)
{
    if (16 > val || 16 == val)
    {
        char pad[16];
        int i = 0;
        for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
            memset(pad + i, *it, 1);
            ++i;
        }
        int v = sizeof(pad) - i;
        char insert = ' ';
        memset(pad + i, insert, v);
        char const* ptr = pad;
        return ptr;

    }
    else if (32 > val || 32 == val)
    {
        char pad[32];
        int i = 0;
        for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
            memset(pad + i, *it, 1);
            ++i;
        }
        int v = sizeof(pad) - i;
        char insert = ' ';
        memset(pad + i, insert, v);
        char const* ptr = pad;
        return ptr;
    }
    else if (64 > val || 64 == val)
    {
        char pad[64];
        int i = 0;
        for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
            memset(pad + i, *it, 1);
            ++i;
        }
        int v = sizeof(pad) - i;
        char insert = ' ';
        memset(pad + i, insert, v);
        char const* ptr = pad;
        return ptr;
    }
    else if (128 > val || 128 == val)
    {
        char pad[128];
        int i = 0;
        for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
            memset(pad + i, *it, 1);
            ++i;
        }
        int v = sizeof(pad) - i;
        char insert = ' ';
        memset(pad + i, insert, v);
        char const* ptr = pad;
        return ptr;
    }
    else if (256 > val || 256 == val)
    {
        char pad[256];
        int i = 0;
        for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
            memset(pad + i, *it, 1);
            ++i;
        }
        int v = sizeof(pad) - i;
        char insert = ' ';
        memset(pad + i, insert, v);
        char const* ptr = pad;
        return ptr;
    }
    else if (512 > val || 512 == val)
    {
        char pad[512];
        int i = 0;
        for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
            memset(pad + i, *it, 1);
            ++i;
        }
        int v = sizeof(pad) - i;
        char insert = ' ';
        memset(pad + i, insert, v);
        char const* ptr = pad;
        return ptr;

    }
    else if (1024 > val || 1024 == val)
    {
        char pad[1024];
        int i = 0;
        for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
            memset(pad + i, *it, 1);
            ++i;
        }
        int v = sizeof(pad) - i;
        char insert = ' ';
        memset(pad + i, insert, v);
        char const* ptr = pad;
        return ptr;
    }
}
#endif

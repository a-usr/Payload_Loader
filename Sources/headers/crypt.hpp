#pragma once
#ifndef CRYPT_H
#define CRYPT_H
//#include "cryptopp/cryptlib.h"
//#include "cryptopp/rijndael.h"
//#include "cryptopp/modes.h"
//#include "cryptopp/files.h"
//#include "cryptopp/osrng.h"
//#include "cryptopp/hex.h"
#include <string>
#include <iostream>
#include "Rijndael.h"
#include "converter.hpp"

//std::string decrypt(std::string cipher, CryptoPP::SecByteBlock key, CryptoPP::SecByteBlock iv)
//{
//    std::string recovered;
//	CryptoPP::CBC_Mode< CryptoPP::AES >::Decryption d;
//	d.SetKeyWithIV(key, key.size(), iv);
//    CryptoPP::StringSource s(cipher, true,
//        new CryptoPP::StreamTransformationFilter(d,
//            new CryptoPP::StringSink(recovered)
//        ) // StreamTransformationFilter
//    ); // StringSource
//    return recovered;
//}

std::string decrypt(std::string cipher, size_t lenght, std::string key)
{
    CRijndael AES;
    AES.MakeKey(key.c_str(), CRijndael::sm_chain0, 16, 16);
    const char *dataIn = pad(cipher, sizeof(cipher));
    char dataOut[1024];
    memset(dataOut, 0, 1024);
    AES.Decrypt(dataIn, dataOut, lenght, 1);

    return dataOut;

}
std::string encrypt(std::string plaintext, size_t lenght, std::string key)
{
    CRijndael AES;
    AES.MakeKey(key.c_str(), CRijndael::sm_chain0, 16, 16);
    const char *ptr;
    ptr = pad(plaintext, lenght);
    char dataOut[1024];
    memset(dataOut, 0, 1024);
    AES.Encrypt(ptr, dataOut, lenght, CRijndael::CBC);
    return dataOut;
}
std::string gen_key() {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(16);

    for (int i = 0; i < 16; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    
    return tmp_s;
}
#endif
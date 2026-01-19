///////////////////////////////////////////////////////////////////////////////
//
// Project       : File Encryption/Decryption DLL
// File Name     : EncryptDecrypt.cpp
// Description   : This file contains four exported functions for performing 
//                 Caesar Cipher and XOR Cipher encryption/decryption on files.
// Author        : Pradnya Subhash Chaudhari
// Platform      : Windows (DLL)
//
///////////////////////////////////////////////////////////////////////////////

#include <Windows.h>
#include <fcntl.h>
#include <io.h>
#include "pch.h"
#include <cstdlib>
#include <iostream>

using namespace std;

#define MAX_SIZE 1024  // Buffer size for reading/writing files

///////////////////////////////////////////////////////////////////////////////
//
// Function      : Encrypt_Caesar_Cipher
// Description   : Encrypts a file using Caesar Cipher and writes output to another file
// Parameters    : Src, Dest, key  
// Return Value  : None
// Exported      : Yes
// Author        : Pradnya Subhash Chaudhari
// Date          : 13/09/2025
//
///////////////////////////////////////////////////////////////////////////////

extern "C" __declspec(dllexport) void Encrypt_Caesar_Cipher(
                                                                char* Src,    //path to source file
                                                                char* Dest,   //path to destination file
                                                                int Key       // Caesar shift value
                                                            );

void Encrypt_Caesar_Cipher(char* Src, char* Dest, int Key)
{
    int fdSrc = 0, fdDest = 0, iRet = 0;
    char Buffer[MAX_SIZE] = { '\0' };

    fdSrc = _open(Src, O_RDONLY);
    if (fdSrc == -1)
    {
        cout << "Unable to open source file\n";
        return;
    }

    fdDest = _open(Dest, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fdDest == -1)
    {
        cout << "Unable to create destination file\n";
        return;
    }

    // Read from source and encrypt using Caesar cipher
    while ((iRet = _read(fdSrc, Buffer, sizeof(Buffer))) > 0)
    {
        for (int i = 0; i < iRet; i++)
        {
            Buffer[i] = (Buffer[i] + Key) % 256;
        }

        _write(fdDest, Buffer, iRet);
    }

    _close(fdSrc);
    _close(fdDest);
}

///////////////////////////////////////////////////////////////////////////////
//
// Function      : Encrypt_XOR_Cipher
// Description   : Encrypts a file using XOR Cipher and writes output to another file
// Parameters    : Src, Dest, key  
// Return Value  : None
// Exported      : Yes
// Author        : Pradnya Subhash Chaudhari
// Date          : 13/09/2025
//
///////////////////////////////////////////////////////////////////////////////

extern "C" __declspec(dllexport) void Encrypt_XOR_Cipher(
                                                            char* Src,         //path to source file
                                                            char* Dest,        //path to destination file
                                                            char Key           //XOR Key
                                                        );

void Encrypt_XOR_Cipher(char* Src, char* Dest, char Key)
{
    int fdSrc = 0, fdDest = 0, iRet = 0;
    char Buffer[MAX_SIZE] = { '\0' };

    fdSrc = _open(Src, O_RDONLY);
    if (fdSrc == -1)
    {
        cout << "Unable to open source file\n";
        return;
    }

    fdDest = _open(Dest, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fdDest == -1)
    {
        cout << "Unable to create destination file\n";
        return;
    }

    // Read from source and encrypt using XOR cipher
    while ((iRet = _read(fdSrc, Buffer, sizeof(Buffer))) > 0)
    {
        for (int i = 0; i < iRet; i++)
        {
            Buffer[i] = Buffer[i] ^ Key;
        }

        _write(fdDest, Buffer, iRet);
    }

    _close(fdSrc);
    _close(fdDest);
}

///////////////////////////////////////////////////////////////////////////////
//
// Function      : Decrypt_XOR_Cipher
// Description   : Decrypts a file that was encrypted using XOR Cipher
// Parameters    : Src, Dest, key  
// Return Value  : None
// Exported      : Yes
// Author        : Pradnya Subhash Chaudhari
// Date          : 13/09/2025
//
///////////////////////////////////////////////////////////////////////////////

extern "C" __declspec(dllexport) void Decrypt_XOR_Cipher(
                                                            char* Src,         //path to encrypted file
                                                            char* Dest,        //path to decrypted output file
                                                            char Key           //same XOR key used during encryption
                                                        );

void Decrypt_XOR_Cipher(char* Src, char* Dest, char Key)
{
    int fdSrc = 0, fdDest = 0, iRet = 0;
    char Buffer[MAX_SIZE] = { '\0' };

    fdSrc = _open(Src, O_RDONLY);
    if (fdSrc == -1)
    {
        cout << "Unable to open source file\n";
        return;
    }

    fdDest = _open(Dest, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fdDest == -1)
    {
        cout << "Unable to create destination file\n";
        return;
    }

    // Read from source and decrypt using XOR cipher
    while ((iRet = _read(fdSrc, Buffer, sizeof(Buffer))) > 0)
    {
        for (int i = 0; i < iRet; i++)
        {
            Buffer[i] = Buffer[i] ^ Key;
        }

        _write(fdDest, Buffer, iRet);
    }

    _close(fdSrc);
    _close(fdDest);
}

///////////////////////////////////////////////////////////////////////////////
//
// Function      : Decrypt_Caesar_Cipher
// Description   : Decrypts a file that was encrypted using Caesar Cipher
// Parameters    : Src, Dest, key  
// Return Value  : None
// Exported      : Yes
// Author        : Pradnya Subhash Chaudhari
// Date          : 13/09/2025
//
///////////////////////////////////////////////////////////////////////////////

extern "C" __declspec(dllexport) void Decrypt_Caesar_Cipher(
                                                                char* Src,        //path to encrypted file
                                                                char* Dest,       //path to decrypted output file
                                                                int Key           //Caesar shift value used during encryption
                                                            );

void Decrypt_Caesar_Cipher(char* Src, char* Dest, int Key)
{
    int fdSrc = 0, fdDest = 0, iRet = 0;
    char Buffer[MAX_SIZE] = { '\0' };

    fdSrc = _open(Src, O_RDONLY);
    if (fdSrc == -1)
    {
        cout << "Unable to open source file\n";
        return;
    }

    fdDest = _open(Dest, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fdDest == -1)
    {
        cout << "Unable to create destination file\n";
        return;
    }

    // Read from source and decrypt using Caesar cipher
    while ((iRet = _read(fdSrc, Buffer, sizeof(Buffer))) > 0)
    {
        for (int i = 0; i < iRet; i++)
        {
            Buffer[i] = (Buffer[i] - Key + 256) % 256;
        }

        _write(fdDest, Buffer, iRet);
    }

    _close(fdSrc);
    _close(fdDest);
}

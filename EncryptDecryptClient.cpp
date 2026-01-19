#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <iostream>
#include <windows.h>

using namespace std;

// Function pointer typedefs for Caesar (int key) and XOR (char key)
typedef void (*FPTR_CAESAR)(char*, char*, int);
typedef void (*FPTR_XOR)(char*, char*, char);

int main()
{
    // Load the DLL
    HINSTANCE hdll = LoadLibrary(L"EncryptDecrypt.dll");
    if (hdll == NULL)
    {
        cout << "Unable to load DLL\n";
        return -1;
    }

    // Load Encrypt_Caesar_Cipher function
    FPTR_CAESAR fpEncryptCaesar = (FPTR_CAESAR)GetProcAddress(hdll, "Encrypt_Caesar_Cipher");
    if (fpEncryptCaesar == NULL)
    {
        cout << "Unable to get address of Encrypt_Caesar_Cipher\n";
        FreeLibrary(hdll);
        return -1;
    }

    // Load Decrypt_Caesar_Cipher function
    FPTR_CAESAR fpDecryptCaesar = (FPTR_CAESAR)GetProcAddress(hdll, "Decrypt_Caesar_Cipher");
    if (fpDecryptCaesar == NULL)
    {
        cout << "Unable to get address of Decrypt_Caesar_Cipher\n";
        FreeLibrary(hdll);
        return -1;
    }

    // Load Encrypt_XOR_Cipher function
    FPTR_XOR fpEncryptXOR = (FPTR_XOR)GetProcAddress(hdll, "Encrypt_XOR_Cipher");
    if (fpEncryptXOR == NULL)
    {
        cout << "Unable to get address of Encrypt_XOR_Cipher\n";
        FreeLibrary(hdll);
        return -1;
    }

    // Load Decrypt_XOR_Cipher function
    FPTR_XOR fpDecryptXOR = (FPTR_XOR)GetProcAddress(hdll, "Decrypt_XOR_Cipher");
    if (fpDecryptXOR == NULL)
    {
        cout << "Unable to get address of Decrypt_XOR_Cipher\n";
        FreeLibrary(hdll);
        return -1;
    }

    //Caesar Encryption with key = 3
    fpEncryptCaesar("Input.txt", "CaesarEncrypted.txt", 3);
    cout << "File encrypted using Caesar cipher and saved as 'CaesarEncrypted.txt'" << endl;

    //Caesar Decryption with same key
    fpDecryptCaesar("CaesarEncrypted.txt", "CaesarDecrypted.txt", 3);
    cout << "File decrypted using Caesar cipher and saved as 'CaesarDecrypted.txt'" << endl;

    //XOR Encryption with key = 'K'
    fpEncryptXOR("Input.txt", "XOREncrypted.txt", 'K');
    cout << "File encrypted using XOR cipher and saved as 'XOREncrypted.txt'" << endl;

    //XOR Decryption with same key
    fpDecryptXOR("XOREncrypted.txt", "XORDecrypted.txt", 'K');
    cout << "File decrypted using XOR cipher and saved as 'XORDecrypted.txt'" << endl;

    // Unload the DLL after usage
    FreeLibrary(hdll);

    return 0;
}

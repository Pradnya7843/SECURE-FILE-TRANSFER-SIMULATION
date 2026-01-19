# SECURE-FILE-TRANSFER-SIMULATION
------------------------------------------------------------------------

-Project Type     : File Encryption & Decryption using DLL

-Language         : C++

-Platform         : Windows (WinAPI and DLL)

-Author           : Pradnya Subhash Chaudhari

-Created Date     : 13/09/2025

PROJECT DESCRIPTION:
-----------------------------------------------------------------------

This project demonstrates file encryption and decryption using two 
well-known cryptographic techniques:
    1. Caesar Cipher
    2. XOR Cipher

The core encryption/decryption logic is implemented inside a **Windows DLL**
(`EncryptDecrypt.dll`). A separate client application (EXE) dynamically 
loads the DLL and invokes the desired operations at runtime.

This modular approach allows the encryption logic to be reused or updated
independently of the application.

PROJECT STRUCTURE
----------------------------------------------------------------------

1. EncryptDecrypt.dll
   - Contains four exported functions:
       • Encrypt_Caesar_Cipher
       • Decrypt_Caesar_Cipher
       • Encrypt_XOR_Cipher
       • Decrypt_XOR_Cipher

2. MainDriverApp.cpp
   - Loads the DLL dynamically at runtime using LoadLibrary
   - Resolves function addresses using GetProcAddress
   - Calls required encryption/decryption functions
   - Example input file: Input.txt
   - Output files are generated accordingly

FUNCTIONALITY
-----------------------------------------------------------------------

1. Caesar Cipher:
   - Shifts each byte by a key value (mod 256).
   - Useful for demonstrating basic encryption logic.

2. XOR Cipher:
   - Applies XOR logic on each byte with a given key.
   - More secure than Caesar for basic file obfuscation.

BUILDING THE DLL
-----------------------------------------------------------------------

1. Create a new DLL project in Visual Studio.
2. Add the `EncryptDecrypt.cpp` file.
3. Export the following functions using `__declspec(dllexport)`:

       void Encrypt_Caesar_Cipher(char*, char*, int);
       void Decrypt_Caesar_Cipher(char*, char*, int);
       void Encrypt_XOR_Cipher(char*, char*, char);
       void Decrypt_XOR_Cipher(char*, char*, char);

4. Compile the project to generate `EncryptDecrypt.dll`.

RUNNING THE APPLICATION
-----------------------------------------------------------------------

1. Ensure the following files are present in the working directory:
    - `EncryptDecrypt.dll`
    - `Input.txt` (the file you want to encrypt)
    - `MainDriverApp.exe` (the compiled driver program)

2. Run the driver application. It will:
    - Encrypt the file using Caesar and XOR cipher.
    - Decrypt the file using respective methods.
    - Create 4 output files:
        • CaesarEncrypted.txt
        • CaesarDecrypted.txt
        • XOREncrypted.txt
        • XORDecrypted.txt

3. Verify that decrypted files match the original input file.

EXAMPLE USAGE IN DRIVER APPLICATION
-----------------------------------------------------------------------

    Encrypt_Caesar_Cipher("Input.txt", "CaesarEncrypted.txt", 3);
    Decrypt_Caesar_Cipher("CaesarEncrypted.txt", "CaesarDecrypted.txt", 3);

    Encrypt_XOR_Cipher("Input.txt", "XOREncrypted.txt", 'K');
    Decrypt_XOR_Cipher("XOREncrypted.txt", "XORDecrypted.txt", 'K');

REQUIREMENTS
-----------------------------------------------------------------------

• Windows OS

• Visual Studio (for building the DLL)

• C++17 or compatible compiler

• Basic understanding of DLLs and file I/O

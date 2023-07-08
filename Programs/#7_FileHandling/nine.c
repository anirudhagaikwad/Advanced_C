/*
Write a program to decrypt the contents of an encrypted text file.
*/

#include <stdio.h>

int main() {
    FILE *encryptedFile, *decryptedFile;
    char ch;
    int shift = 3;

    // Open the encrypted file in read mode
    encryptedFile = fopen("encrypted.txt", "r");
    if (encryptedFile == NULL) {
        printf("Unable to open the encrypted file.\n");
        return 1;
    }

    // Open the decrypted file in write mode
    decryptedFile = fopen("decrypted.txt", "w");
    if (decryptedFile == NULL) {
        printf("Unable to create the decrypted file.\n");
        fclose(encryptedFile);
        return 1;
    }

    // Decrypt and write the contents to the decrypted file
    while ((ch = fgetc(encryptedFile)) != EOF) {
        ch = ch - shift;
        fputc(ch, decryptedFile);
    }

    // Close the files
    fclose(encryptedFile);
    fclose(decryptedFile);

    printf("File decrypted successfully.\n");

    return 0;
}
/*
This program decrypts the contents of an encrypted text file ("encrypted.txt") by shifting each character back by a fixed number of positions
(in this case, 3). It opens the encrypted file in read mode and the decrypted file in write mode. Then, it reads each character from the encrypted file,
applies the reverse shift, and writes the decrypted character to the decrypted file.
Finally, it closes both files and displays a success message.
*/

/*
Write a program to encrypt the contents of a text file by shifting each character by a fixed number of positions.
*/
#include <stdio.h>

int main() {
    FILE *sourceFile, *targetFile;
    char ch;
    int shift = 3;

    // Open the source file in read mode
    sourceFile = fopen("source.txt", "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    // Open the target file in write mode
    targetFile = fopen("target.txt", "w");
    if (targetFile == NULL) {
        printf("Unable to create the target file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Encrypt and write the contents to the target file
    while ((ch = fgetc(sourceFile)) != EOF) {
        ch = ch + shift;
        fputc(ch, targetFile);
    }

    // Close the files
    fclose(sourceFile);
    fclose(targetFile);

    printf("File encrypted successfully.\n");

    return 0;
}
/*
This program encrypts the contents of a text file ("source.txt") by shifting each character by a fixed number of positions (in this case, 3).
It opens the source file in read mode and the target file in write mode.
Then, it reads each character from the source file, applies the shift, and writes the encrypted character to the target file.
Finally, it closes both files and displays a success message.
*/

/*

Write a program that copies the content of one file to another.
Read the content from the source file named "source.txt" and write it to the destination file named "destination.txt".

Input: A text file named "source.txt" with content.
Output: A text file named "destination.txt" with the same content as the source file.
*/

#include <stdio.h>

int main() {
    FILE *source, *destination;
    char ch;

    source = fopen("source.txt", "r"); //opening the file in read mode
    if (source == NULL) {
        printf("Error opening source file.\n");
        return 1;
    }

    destination = fopen("destination.txt", "w"); //opening the file in write mode
    if (destination == NULL) {
        printf("Error opening destination file.\n");
        fclose(source);
        return 1;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    //closing files
    fclose(source);
    fclose(destination);

    printf("File copied successfully.\n");

    return 0;
}
/*
This program reads the content of a source file named "source.txt" and copies it to a destination file named "destination.txt".
It uses two file pointers, one for reading the source file and another for writing to the destination file. The program reads each character from the source file using fgetc() and writes it to the destination file using fputc() until the end of the file is reached.
Finally, it closes both files and displays a success message.
*/

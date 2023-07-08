/*
Write a program to concatenate two files and save the result in a new file.
*/
#include <stdio.h>

int main() {
    FILE *file1, *file2, *resultFile;
    char ch;

    // Open the first file in read mode
    file1 = fopen("file1.txt", "r");
    if (file1 == NULL) {
        printf("Unable to open file1.\n");
        return 1;
    }

    // Open the second file in read mode
    file2 = fopen("file2.txt", "r");
    if (file2 == NULL) {
        printf("Unable to open file2.\n");
        fclose(file1);
        return 1;
    }

    // Open the result file in write mode
    resultFile = fopen("result.txt", "w");
    if (resultFile == NULL) {
        printf("Unable to create the result file.\n");
        fclose(file1);
        fclose(file2);
        return 1;
    }

    // Copy the contents of file1 to the result file
    while ((ch = fgetc(file1)) != EOF) {
        fputc(ch, resultFile);
    }

    // Copy the contents of file2 to the result file
    while ((ch = fgetc(file2)) != EOF) {
        fputc(ch, resultFile);
    }

    // Close the files
    fclose(file1);
    fclose(file2);
    fclose(resultFile);

    printf("Files concatenated successfully.\n");

    return 0;
}
/*
This program concatenates the contents of two files ("file1.txt" and "file2.txt") and saves the result in a new file ("result.txt").
It opens the first and second files in read mode, and the result file in write mode. Then, it reads each character from file1 and writes it to the result file. After that, it reads each character from file2 and writes it to the result file.
Finally, it closes all the files and displays a success message.
*/

/*
Write a program that reads a file and counts the number of characters present in it. Print the total character count.

Input: A text file named "input.txt" with content.
Output: Total character count.
*/

#include <stdio.h>

int main() {
    FILE *file;
    char ch;
    int count = 0;

    file = fopen("input.txt", "r"); //opening th file in read mode
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        count++; //count characters in file while its not reach to end of file
    }

    fclose(file); //close file

    printf("Total characters: %d\n", count);

    return 0;
}
/*
This program reads a file named "input.txt" and counts the number of characters present in it.
It uses a file pointer and the fgetc() function to read each character until the end of the file is reached.
The program then prints the total character count.
*/

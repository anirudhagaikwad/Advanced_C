/*
Write a C Program that involves manipulating an array of strings based on a given condition.
The program allows sorting and filtering of the strings based on different criteria using function pointers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 5
#define MAX_LENGTH 50

// Function pointer type for string comparison
typedef int (*StringComparator)(const char*, const char*);

// Function pointer type for string filtering
typedef int (*StringFilter)(const char*);

// Function to compare two strings lexicographically
int compareStrings(const char* str1, const char* str2) {
    return strcmp(str1, str2);
}

// Function to compare two strings based on length
int compareStringLength(const char* str1, const char* str2) {
    return strlen(str1) - strlen(str2);
}

// Function to filter strings based on length greater than a given threshold
int filterByLength(const char* str) {
    int threshold = 5;  // Length threshold for filtering

    return strlen(str) > threshold;
}

// Function to filter strings based on starting with a given character
int filterByStartingChar(const char* str) {
    char startChar = 'A';  // Starting character for filtering

    return str[0] == startChar;
}

// Function to perform array sorting or filtering based on function pointers
void processStrings(const char* strings[], int size, StringComparator comparator, StringFilter filter) {
    // Sort the strings using the provided comparator function pointer
    qsort(strings, size, sizeof(const char*), (int (*)(const void*, const void*))comparator);

    // Filter the strings using the provided filter function pointer
    printf("Filtered strings:\n");
    for (int i = 0; i < size; i++) {
        if (filter(strings[i])) {
            printf("%s\n", strings[i]);
        }
    }
}

int main() {
    const char* strings[MAX_STRINGS] = {
        "Hello",
        "OpenAI",
        "World",
        "Interview",
        "Language"
    };

    int size = sizeof(strings) / sizeof(strings[0]);

    printf("Original strings:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", strings[i]);
    }

    printf("\nSorting strings lexicographically:\n");
    processStrings(strings, size, compareStrings, NULL);

    printf("\nSorting strings based on length:\n");
    processStrings(strings, size, compareStringLength, NULL);

    printf("\nFiltering strings based on length:\n");
    processStrings(strings, size, NULL, filterByLength);

    printf("\nFiltering strings based on starting character:\n");
    processStrings(strings, size, NULL, filterByStartingChar);

    return 0;
}

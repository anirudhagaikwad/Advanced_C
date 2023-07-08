/*
 Write a C program using Function Pointer  to Compare Two Strings

 Input:
 Enter the first string: hello
 Enter the second string: sky

 Output:
 String 1 is less than String 2

 Input:
 Enter the first string: hello
 Enter the second string: hello

 Output:
 String 1 is equal to String 2

 Input:
 Enter the first string: Rain
 Enter the second string: Apple

 Output:
 String 1 is greater than String 2

*/

#include <stdio.h>
#include <string.h>

int compareStrings(const char *str1, const char *str2) {
    return strcmp(str1, str2);
}

int main() {
    char str1[100], str2[100];
    int (*compare)(const char *, const char *);

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    // Assign the string comparison function to the function pointer
    compare = compareStrings;

    // Call the string comparison function using the function pointer
    int result = compare(str1, str2);

    if (result < 0) {
        printf("String 1 is less than String 2\n");
    } else if (result > 0) {
        printf("String 1 is greater than String 2\n");
    } else {
        printf("String 1 is equal to String 2\n");
    }

    return 0;
}

/*
 This program demonstrates the usage of a function pointer to compare two strings.
 The program uses the strcmp function from the <string.h> library to compare two strings. The main function prompts the user to enter two strings,
 assigns the compareStrings function to a function pointer named compare, and then uses the function pointer to call the string comparison function.
 The result is then used to determine and display whether the first string is less than, greater than, or equal to the second string.
*/

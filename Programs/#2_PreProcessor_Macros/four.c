/*
C program to Check whether the certain macro is defined or not.
*/

#include <stdio.h>

#define DEBUG

int main() {
    #ifdef DEBUG
        printf("Debug mode is enabled.\n");
    #else
        printf("Debug mode is disabled.\n");
    #endif

    return 0;
}
/*
This program demonstrates conditional compilation using the
#ifdef directive to check if the DEBUG macro is defined.
The corresponding message is printed based
on whether DEBUG is defined or not.
*/


/*
C Program to perform conditional compilation based on the value of a
constant using preprocessor directive.

*/

#include <stdio.h>

#define OS_WINDOWS 1
#define OS_LINUX 2

#define OS OS_WINDOWS

int main() {
    #if OS == OS_WINDOWS
        printf("Running on Windows.\n");
    #elif OS == OS_LINUX
        printf("Running on Linux.\n");
    #else
        printf("Running on an unknown operating system.\n");
    #endif

    return 0;
}
/*
This program demonstrates conditional compilation based on the
value of a constant. The OS macro is defined to represent the
current operating system, and the corresponding message
is printed based on the value of OS.
*/

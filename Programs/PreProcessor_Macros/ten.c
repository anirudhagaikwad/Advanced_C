/*
C Program to generate the compilation error on particular situation using predefined macros.
*/

#include <stdio.h>

#ifndef MY_CONSTANT
    #error "MY_CONSTANT is not defined!"
#endif

int main() {
    printf("Program execution continues.\n");

    return 0;
}

/*
This program uses the #error directive to generate a compilation error
if the MY_CONSTANT macro is not defined.
*/

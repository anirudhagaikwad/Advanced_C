/*
C Program to print current Date and Time Using predefined macros.
*/
#include <stdio.h>

int main() {
    printf("Program compiled on %s at %s\n", __DATE__, __TIME__);

    return 0;
}

/*
This program uses the predefined macros __DATE__ and __TIME__
to print the date and time when the program was compiled.
*/

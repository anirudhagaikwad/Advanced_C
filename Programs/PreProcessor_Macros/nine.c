/*
C Program to print the name of the current executing function in C using predefined macros.
*/
#include <stdio.h>

void myFunction() {
    printf("This function is: %s\n", __func__);
}

int main() {
    myFunction();

    return 0;
}

/*
This program uses the predefined macro __func__ to print the name of the current function.
*/

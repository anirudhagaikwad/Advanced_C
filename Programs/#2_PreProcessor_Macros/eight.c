/*
C Program to print Line number of statement executing in C using predefined macros.
*/
#include <stdio.h>

int main() {
    printf("This statement is on line %d.\n", __LINE__);

    return 0;
}
/*
This program uses the predefined macro __FILE__ to print the name of the current source file.
*/


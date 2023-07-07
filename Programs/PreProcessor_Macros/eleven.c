/*
C Program to Swap two numbers using predefined macros.

Input: 5,10
Output: Before swap: x = 5, y = 10
        After swap: x = 10, y = 5

Input: 100,5
Output: Before swap: x = 100, y = 5
        After swap: x = 5, y = 100

Input: 87,65
Output: Before swap: x = 87, y = 65
        After swap: x = 65, y = 87


*/

#include <stdio.h>

#define SWAP(a, b) do { \
                        int temp = (a); \
                        (a) = (b); \
                        (b) = temp; \
                    } while (0)

int main() {
    int x = 5, y = 10;
    printf("Before swap: x = %d, y = %d\n", x, y);
    SWAP(x, y); //cal  SWAP Macro
    printf("After swap: x = %d, y = %d\n", x, y);

    return 0;
}

/*
This program demonstrates how to swap two numbers using a macro.
The SWAP macro uses a do-while loop to ensure correct behavior in all cases,
even if the macro is used inside an if statement.
*/


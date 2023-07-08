/*
C Program to terminate running program if input value is negative.

Input: 10
Output: All is well

Input: -5
Output: Assertion error

Input: 0
Output: Assertion error

*/

#include <assert.h>

int main() {
    int num = -5;

    assert(num > 0);

    printf("All is well"); //will not execute if above assert statement failed

    return 0;
}

/*
This program uses the assert macro from the <assert.h> header to perform runtime assertion checking.
If the condition inside the assert macro evaluates to false, the program terminates with an error message.
*/

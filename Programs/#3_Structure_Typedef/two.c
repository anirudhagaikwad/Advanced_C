/*
C Program to swap coordinates X and Y of two structures.

Input: p1- 10,20
       p2- 30,40

Output:
        Before swapping:
        p1.x = 10, p1.y = 20
        p2.x = 30, p2.y = 40
        After swapping:
        p1.x = 30, p1.y = 40
        p2.x = 10, p2.y = 20

*/

#include <stdio.h>

// Structure definition
struct Point {
    int x;
    int y;
};

int main() {
    // Structure variable declaration and initialization
    struct Point p1 = {10, 20};
    struct Point p2 = {30, 40};

    // Printing original values
    printf("Before swapping:\n");
    printf("p1.x = %d, p1.y = %d\n", p1.x, p1.y);
    printf("p2.x = %d, p2.y = %d\n", p2.x, p2.y);

    // Swapping structures
    struct Point temp;
    temp = p1;
    p1 = p2;
    p2 = temp;

    // Printing swapped values
    printf("After swapping:\n");
    printf("p1.x = %d, p1.y = %d\n", p1.x, p1.y);
    printf("p2.x = %d, p2.y = %d\n", p2.x, p2.y);

    return 0;
}
/*
In above program we have struct for points X and Y.
We have created 2 variables of struct and swapped their X and Y coordinates.
*/


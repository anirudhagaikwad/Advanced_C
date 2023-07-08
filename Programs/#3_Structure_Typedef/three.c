
/*
C program to calculate Area and Perimeter of Rectangle using Structure.

Input: 5,3
Output: Area: 15
        Perimeter: 16

Input: 10,7
Output: Area: 70
        Perimeter: 34

*/
#include <stdio.h>

struct Rectangle {
    //declare variables
    int length;
    int width;
};

int main() {
    struct Rectangle rect; //declare struct type variable
    //assign values to variables in struct
    rect.length = 5;
    rect.width = 3;

    int area = rect.length * rect.width;
    int perimeter = 2 * (rect.length + rect.width);

    printf("Area: %d\n", area);
    printf("Perimeter: %d\n", perimeter);

    return 0;
}
/*
In above program we have one structure contains length and width.
By creating variables of that structure we have calculated Area & Perimeter of Rectangle.

*/

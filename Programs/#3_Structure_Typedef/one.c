/*
C program to demonstrate Structure.
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

    printf("Length: %d\n", rect.length);
    printf("Width: %d\n", rect.width);

    // Printing size of structure
    printf("Size of Rectangle structure: %lu bytes\n", sizeof(struct Rectangle));

    return 0;
}
/*
In above program we have one structure contains length and width.
By creating variables of that structure we have calculated Area & Perimeter of Rectangle.

*/

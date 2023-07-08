/*
Create a struct and create a function that accepts parameters required to create struct and return struct  created from given parameters.
*/

#include <stdio.h>

// Structure definition
struct Point {
    int x;
    int y;
};

// Function to create and return a structure
struct Point createPoint(int x, int y) {
    struct Point p;
    p.x = x;
    p.y = y;
    return p;
}

int main() {
    // Function call to create a structure
    struct Point point = createPoint(5, 10);

    // Printing structure members
    printf("Point: (%d, %d)\n", point.x, point.y);

    return 0;
}

/*
we have Point structure which has X and Y integers.

We have created function that accepts X and Y and return structure by assigning  X and Y.

Inside main we have created struct variable of Point structure and assigned it to the createPoint() function which return the struct.

Finally we have printed data of Point struct.

*/

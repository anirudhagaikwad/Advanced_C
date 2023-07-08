/*
Create pointer to structure and access it with alternative name.
*/

#include <stdio.h>

// Structure definition
typedef struct {
    int x;
    int y;
} Point;

int main() {
    // Typedef for pointer to structure
    typedef Point* PointPtr;

    // Structure variable declaration and initialization
    Point point = {10, 20};

    // Pointer to structure
    PointPtr ptr = &point;

    // Accessing and printing structure members using pointer
    printf("Point: (%d, %d)\n", ptr->x, ptr->y);

    return 0;
}

/*
In above program we have created alias name for pointer to structure.
*/


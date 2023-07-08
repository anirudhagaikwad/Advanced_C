/*
Create structure for coordinates and access it with alternative name.

*/

#include <stdio.h>

// Structure definition using typedef
typedef struct {
    int x;
    int y;
} Point;

int main() {
    // Structure variable declaration and initialization
    Point p = {10, 20};

    // Accessing and printing structure members
    printf("Point: (%d, %d)\n", p.x, p.y);

    return 0;
}

/*
In above program we have created alias name for structure.

Using typedef struct results in a cleaner, more readable code

Using typedef there is no longer a need to type struct again and again with every declaration of the variable of this type.
*/

/*
Write function to calculate area of the Rectangle which accepts structure as parameter.

Input: 7,5
Output: Area of rectangle: 35

*/


#include <stdio.h>

// Structure definition
struct Rectangle {
    float length;
    float width;
};

// Function to calculate area of rectangle
float calculateArea(struct Rectangle rect) {
    return rect.length * rect.width;
}

int main() {
    // Structure variable declaration and initialization
    struct Rectangle rect = {10.5, 5.5};

    // Calculating and printing area
    float area = calculateArea(rect);
    printf("Area of rectangle: %.2f\n", area);

    return 0;
}

/*
We have struct Rectangle which contains length and width.

We have calculateArea function which accepts Rectangle struct as parameter and returns area of rectangle.

Inside main we have created variable of struct type and passed that to calculateArea function.

calculateArea returns the area of rectangle.

*/

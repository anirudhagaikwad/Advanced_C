/*
Write a struct for length and width of Rectange.
Create a function that accepts Variable of type struct Rectangle with alternative name and returns Area of Rectangle.

Input: 12.5,7.4
Output: Area of rectangle: 92.50

*/

#include <stdio.h>

// Structure definition using typedef
typedef struct {
    float length;
    float width;
} Rectangle;

// Function to calculate area of rectangle
float calculateArea(Rectangle rect) {
    return rect.length * rect.width;
}

int main() {
    // Structure variable declaration and initialization
    Rectangle rect = {12.5, 7.4};

    // Calculating and printing area
    float area = calculateArea(rect);
    printf("Area of rectangle: %.2f\n", area);

    return 0;
}
/*
We have struct Rectangle which contains length and width.

We have calculateArea function which accepts Rectangle struct with alias name as parameter and returns area of rectangle.

Inside main we have created variable of struct type and passed that to calculateArea function.

calculateArea returns the area of rectangle.
*/

/*
Implement C Program to calculate Area of Triangle using Inline Function.

Formula:
Area of Triangle: (base*height)/2

Input: Enter the base of the triangle: 7
       Enter the height of the triangle: 9

Output: Area of the triangle is: 31.50

*/

#include <stdio.h>

// function to calculate area of triangle
static inline float calculateTriangleArea(float base, float height) {
    return (base * height) / 2;
}

int main() {
    float base, height;

    printf("Enter the base of the triangle: ");
    scanf("%f", &base); //input base of the triangle

    printf("Enter the height of the triangle: ");
    scanf("%f", &height); //input height of the triangle

    float area = calculateTriangleArea(base, height);

    printf("Area of the triangle is: %.2f\n", area);

    return 0;
}
/*
This program calculates the area of a triangle using an inline function calculateTriangleArea().
The user is prompted to enter the base and height of the triangle, and the calculateTriangleArea() function is called to
compute the area based on the provided values.
The resulting area is then displayed on the screen.
*/

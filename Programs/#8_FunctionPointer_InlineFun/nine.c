/*
Implement C Program to calculate Area of the circle using Inline Function.
Constant: PI value is 3.1415

Input: Enter the radius of the circle: 7
Output: Area of the circle is: 153.93

*/

#include <stdio.h>

#define PI 3.1415  //define constant

static inline float calculateArea(float radius) {
    return PI * radius * radius; //calculate area = PI*radius*radius
}

int main() {
    float radius;

    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    float area = calculateArea(radius);

    printf("Area of the circle is: %.2f\n", area);

    return 0;
}

/*
This program calculates the area of a circle using an inline function calculateArea().
The user is prompted to enter the radius of the circle, and the calculateArea() function is called to compute the
area based on the provided radius.
The result is then displayed on the screen.
*/

/* Perform operations on circles using structures.
   Each circle has a radius.

   Input:
    Enter the radius of the circle: 5

   Output:
    Diameter: 10.00
    Circumference: 31.42
    Area: 78.54

*/

#include <stdio.h>
#define PI 3.14159

// Structure definition for Circle
struct Circle {
    float radius;
};

// Function to calculate the diameter of a circle
float calculateDiameter(struct Circle cir) {
    return 2 * cir.radius;
}

// Function to calculate the circumference of a circle
float calculateCircumference(struct Circle cir) {
    return 2 * PI * cir.radius;
}

// Function to calculate the area of a circle
float calculateArea(struct Circle cir) {
    return PI * cir.radius * cir.radius;
}

int main() {
    // Creating circle structure
    struct Circle cir;

    // Inputting circle radius
    printf("Enter the radius of the circle: ");
    scanf("%f", &cir.radius);

    // Calculating diameter, circumference, and area
    float diameter = calculateDiameter(cir);
    float circumference = calculateCircumference(cir);
    float area = calculateArea(cir);

    // Displaying the results
    printf("\nDiameter: %.2f\n", diameter);
    printf("Circumference: %.2f\n", circumference);
    printf("Area: %.2f\n", area);

    return 0;
}

/*
This program performs operations on circles using structures.
It defines a structure for circles and implements functions to calculate the diameter, circumference, and area.
The program allows the user to input the radius of a circle and displays the calculated values.
*/

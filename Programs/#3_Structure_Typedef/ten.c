/* Calculate the area of a triangle using structures.
Each triangle has three sides.

Input:
    Enter the sides of the triangle:
    Side 1: 23
    Side 2: 22
    Side 3: 21

Output:
    Area of the triangle: 208.71

*/

#include <stdio.h>
#include <math.h>

// Structure definition for Triangle
struct Triangle {
    float side1;
    float side2;
    float side3;
};

// Function to calculate the area of a triangle
float calculateArea(struct Triangle tri) {
    float s = (tri.side1 + tri.side2 + tri.side3) / 2;
    return sqrt(s * (s - tri.side1) * (s - tri.side2) * (s - tri.side3));
}

int main() {
    // Creating triangle structure
    struct Triangle tri;

    // Inputting triangle sides
    printf("Enter the sides of the triangle:\n");
    printf("Side 1: ");
    scanf("%f", &tri.side1);
    printf("Side 2: ");
    scanf("%f", &tri.side2);
    printf("Side 3: ");
    scanf("%f", &tri.side3);

    // Calculating the area
    float area = calculateArea(tri);

    // Displaying the result
    printf("\nArea of the triangle: %.2f\n", area);

    return 0;
}

/*
This program calculates the area of a triangle using structures.
It defines a structure for triangles and implements a function to compute the area.
The program allows the user to input the lengths of the three sides of a triangle and displays the area.
*/

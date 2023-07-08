/* Calculate the area of different shapes using a union to represent different types of shapes.
The program can calculate the area of a rectangle, triangle, or circle.
*/

#include <stdio.h>

// Union definition for Shape
union Shape {
    struct {
        float length;
        float width;
    } rectangle;

    struct {
        float base;
        float height;
    } triangle;

    float radius;
};

// Function to calculate the area of a rectangle
float calculateRectangleArea(float length, float width) {
    return length * width;
}

// Function to calculate the area of a triangle
float calculateTriangleArea(float base, float height) {
    return (base * height) / 2;
}

// Function to calculate the area of a circle
float calculateCircleArea(float radius) {
    return 3.14159 * radius * radius;
}

int main() {
    // Creating a shape union
    union Shape shape;

    // Calculating the area of a rectangle
    shape.rectangle.length = 5;
    shape.rectangle.width = 3;
    float rectangleArea = calculateRectangleArea(shape.rectangle.length, shape.rectangle.width);

    // Calculating the area of a triangle
    shape.triangle.base = 4;
    shape.triangle.height = 6;
    float triangleArea = calculateTriangleArea(shape.triangle.base, shape.triangle.height);

    // Calculating the area of a circle
    shape.radius = 2.5;
    float circleArea = calculateCircleArea(shape.radius);

    // Displaying the results
    printf("Rectangle Area: %.2f\n", rectangleArea);
    printf("Triangle Area: %.2f\n", triangleArea);
    printf("Circle Area: %.2f\n", circleArea);

    return 0;
}

/*
This program demonstrates the use of a union to calculate the area of different shapes, including rectangles, triangles, and circles.
The union Shape contains nested structures for rectangle and triangle, as well as a single float for the radius of a circle.
The program calculates the area of a rectangle, triangle, and circle using respective area calculation functions.
The results are displayed accordingly.
*/

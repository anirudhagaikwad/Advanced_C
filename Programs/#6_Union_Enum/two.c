/*
Calculate the area and perimeter of different shapes using union.
The program can calculate the area and perimeter of a rectangle or a circle.
 */

#include <stdio.h>

// Union definition for Shape
union Shape {
    struct {
        float length;
        float width;
    } rectangle;

    struct {
        float radius;
    } circle;
};

// Function to calculate the area of a rectangle
float calculateRectangleArea(float length, float width) {
    return length * width;
}

// Function to calculate the perimeter of a rectangle
float calculateRectanglePerimeter(float length, float width) {
    return 2 * (length + width);
}

// Function to calculate the area of a circle
float calculateCircleArea(float radius) {
    return 3.14 * radius * radius;
}

// Function to calculate the circumference of a circle
float calculateCircleCircumference(float radius) {
    return 2 * 3.14 * radius;
}

int main() {
    // Creating a shape union
    union Shape shape;

    // Calculating the area and perimeter of a rectangle
    shape.rectangle.length = 5;
    shape.rectangle.width = 3;
    float rectangleArea = calculateRectangleArea(shape.rectangle.length, shape.rectangle.width);
    float rectanglePerimeter = calculateRectanglePerimeter(shape.rectangle.length, shape.rectangle.width);

    // Calculating the area and circumference of a circle
    shape.circle.radius = 4;
    float circleArea = calculateCircleArea(shape.circle.radius);
    float circleCircumference = calculateCircleCircumference(shape.circle.radius);

    // Displaying the results
    printf("Rectangle:\n");
    printf("Area: %.2f\n", rectangleArea);
    printf("Perimeter: %.2f\n", rectanglePerimeter);

    printf("\nCircle:\n");
    printf("Area: %.2f\n", circleArea);
    printf("Circumference: %.2f\n", circleCircumference);

    return 0;
}
/*
This program utilizes a union to calculate the area and perimeter of different shapes, specifically a rectangle and a circle.
The union Shape contains nested structures for rectangle and circle. The program calculates the area and perimeter of a rectangle
with given length and width, as well as the area and circumference of a circle with a given radius.
The results are displayed accordingly.
*/

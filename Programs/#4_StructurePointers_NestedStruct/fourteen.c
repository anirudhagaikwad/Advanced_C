/*
You are tasked with developing a program to calculate the net area of a complex shape in a graphical application.
The shape consists of an outer rectangle and an inner rectangle. Each rectangle is represented by the coordinates of its top-left
and bottom-right corners.

Write a C program that uses structures and functions to calculate the net area of the complex shape.

-Define a structure called "Coordinate" to represent a point with x and y coordinates.
-Define a structure called "Rectangle" to represent a rectangle. It should contain two "Coordinate" structures for the top-left and
 bottom-right corners.
-Define a structure called "ComplexShape" to represent the complex shape. It should contain two "Rectangle" structures for the outer
and inner rectangles.
-Implement a function called "calculateArea" that takes a "Rectangle" structure as a parameter and calculates the area of the rectangle.
-Implement a function called "calculateComplexShapeArea" that takes a "ComplexShape" structure as a parameter. Inside this function,
calculate the areas of the outer and inner rectangles using the "calculateArea" function, and then return the net area by subtracting
the area of the inner rectangle from the area of the outer rectangle.
-In the "main" function, create a "ComplexShape" structure and set the coordinates for the outer and inner rectangles.
-Call the "calculateComplexShapeArea" function with the created "ComplexShape" structure as an argument to calculate the net area
 of the complex shape.

Test your program with different complex shapes by providing different coordinates for the outer and inner rectangles.

Example:
Consider a complex shape where the outer rectangle has a top-left corner at (0, 0) and a bottom-right corner at (10, 8). The inner rectangle has a top-left corner at (2, 2) and a bottom-right corner at (8, 6).

Expected Output:
Area of the complex shape: 60
*/

#include <stdio.h>

// Structure to represent a coordinate
struct Coordinate {
    int x;
    int y;
};

// Structure to represent a rectangle
struct Rectangle {
    struct Coordinate topLeft;
    struct Coordinate bottomRight;
};

// Structure to represent a complex shape
struct ComplexShape {
    struct Rectangle outerRect;
    struct Rectangle innerRect;
};

// Function to calculate the area of a rectangle
int calculateArea(struct Rectangle rect) {
    int length = rect.bottomRight.x - rect.topLeft.x;
    int width = rect.bottomRight.y - rect.topLeft.y;
    return length * width;
}

// Function to calculate the area of a complex shape
int calculateComplexShapeArea(struct ComplexShape shape) {
    int outerArea = calculateArea(shape.outerRect);
    int innerArea = calculateArea(shape.innerRect);
    return outerArea - innerArea;
}

int main() {
    // Create a complex shape
    struct ComplexShape shape;
    shape.outerRect.topLeft.x = 0;
    shape.outerRect.topLeft.y = 0;
    shape.outerRect.bottomRight.x = 10;
    shape.outerRect.bottomRight.y = 8;
    shape.innerRect.topLeft.x = 2;
    shape.innerRect.topLeft.y = 2;
    shape.innerRect.bottomRight.x = 8;
    shape.innerRect.bottomRight.y = 6;

    // Calculate the area of the complex shape
    int area = calculateComplexShapeArea(shape);

    // Display the result
    printf("Area of the complex shape: %d\n", area);

    return 0;
}
/*
In this example, we define a complex nested structure consisting of structures representing coordinates, rectangles, and a complex shape.

The Coordinate structure represents a point with x and y coordinates. The Rectangle structure represents a rectangle by specifying the
top left and
bottom right coordinates. The ComplexShape structure represents a complex shape that consists of an outer rectangle and an inner
rectangle.

The calculateArea function calculates the area of a rectangle by subtracting the x-coordinate of the top left point from the
x-coordinate of the bottom right point and multiplying it by the difference in the y-coordinates.

The calculateComplexShapeArea function calculates the area of a complex shape by calculating the areas of the outer and inner
rectangles and subtracting the inner area from the outer area.

In the main function, we create a complex shape by assigning values to its nested structures. We set the coordinates of the outer
rectangle and the inner rectangle. Then, we calculate the area of the complex shape using the calculateComplexShapeArea function.
Finally, we display the result.

This program demonstrates the use of nested structures to represent a complex shape and perform logical computations, such as
calculating the area of a shape.
*/

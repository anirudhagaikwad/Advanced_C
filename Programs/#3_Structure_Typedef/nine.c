#include <stdio.h>

/* Implement the dot product of two vectors using structures.
 Each vector has dimensions and elements.
*/

// Structure definition for Vector
struct Vector {
    int dimensions;
    float elements[10];
};

// Function to calculate the dot product of two vectors
float calculateDotProduct(struct Vector vec1, struct Vector vec2) {
    float dotProduct = 0;
    int i;

    // Checking if vectors have the same dimensions
    if (vec1.dimensions != vec2.dimensions) {
        printf("Error: Vectors must have the same dimensions.\n");
        return 0;
    }

    // Calculating the dot product
    for (i = 0; i < vec1.dimensions; i++) {
        dotProduct += vec1.elements[i] * vec2.elements[i];
    }

    return dotProduct;
}

int main() {
    // Creating vector structure variables
    struct Vector vec1, vec2;

    // Inputting vector dimensions and elements
    printf("Enter dimensions of the vectors: ");
    scanf("%d", &vec1.dimensions);

    printf("Enter elements of the first vector:\n");
    for (int i = 0; i < vec1.dimensions; i++) {
        scanf("%f", &vec1.elements[i]);
    }
    printf("\n");

    printf("Enter elements of the second vector:\n");
    for (int i = 0; i < vec1.dimensions; i++) {
        scanf("%f", &vec2.elements[i]);
    }
    printf("\n");

    // Calculating the dot product
    float dotProduct = calculateDotProduct(vec1, vec2);

    // Displaying the vectors and the dot product
    printf("Vector 1:\n");
    for (int i = 0; i < vec1.dimensions; i++) {
        printf("%.2f ", vec1.elements[i]);
    }
    printf("\n");

    printf("Vector 2:\n");
    for (int i = 0; i < vec1.dimensions; i++) {
        printf("%.2f ", vec2.elements[i]);
    }
    printf("\n");

    printf("Dot Product: %.2f\n", dotProduct);

    return 0;
}
/*
This program implements the dot product of two vectors using structures.
Each vector has dimensions and elements.
The program allows the user to input the dimensions and elements of two vectors, calculates the dot product using a separate function,
and then displays the vectors and the resulting dot product.
*/

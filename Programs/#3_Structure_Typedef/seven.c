/*
Implement matrix multiplication using structures.
Each matrix has dimensions and elements.

Input:

Enter dimensions of the first matrix:
Rows: 2
Columns: 2
Enter elements of the first matrix:
1
2
3
4

Enter dimensions of the second matrix:
Rows: 2
Columns: 2
Enter elements of the second matrix:
1
2
4
3

Matrix 1:
1 2
3 4

Matrix 2:
1 2
4 3

Output:
Product of matrices:
9 8
19 18

*/

#include <stdio.h>

// Structure definition for Matrix
struct Matrix {
    int rows;
    int columns;
    int elements[10][10];
};

// Function to perform matrix multiplication
void multiplyMatrix(struct Matrix mat1, struct Matrix mat2, struct Matrix* result) {
    int i, j, k;

    // Checking if matrices can be multiplied
    if (mat1.columns != mat2.rows) {
        printf("Error: Matrices cannot be multiplied.\n");
        return;
    }

    // Performing matrix multiplication
    for (i = 0; i < mat1.rows; i++) {
        for (j = 0; j < mat2.columns; j++) {
            result->elements[i][j] = 0;
            for (k = 0; k < mat1.columns; k++) {
                result->elements[i][j] += mat1.elements[i][k] * mat2.elements[k][j];
            }
        }
    }

    result->rows = mat1.rows;
    result->columns = mat2.columns;
}

// Function to display a matrix
void displayMatrix(struct Matrix mat) {
    int i, j;
    for (i = 0; i < mat.rows; i++) {
        for (j = 0; j < mat.columns; j++) {
            printf("%d ", mat.elements[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    // Creating matrix structure variables
    struct Matrix mat1, mat2, product;

    // Inputting matrix dimensions and elements
    printf("Enter dimensions of the first matrix:\n");
    printf("Rows: ");
    scanf("%d", &mat1.rows);
    printf("Columns: ");
    scanf("%d", &mat1.columns);
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < mat1.rows; i++) {
        for (int j = 0; j < mat1.columns; j++) {
            scanf("%d", &mat1.elements[i][j]);
        }
    }
    printf("\n");

    printf("Enter dimensions of the second matrix:\n");
    printf("Rows: ");
    scanf("%d", &mat2.rows);
    printf("Columns: ");
    scanf("%d", &mat2.columns);
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < mat2.rows; i++) {
        for (int j = 0; j < mat2.columns; j++) {
            scanf("%d", &mat2.elements[i][j]);
        }
    }
    printf("\n");

    // Multiplying matrices
    multiplyMatrix(mat1, mat2, &product);

    // Displaying matrices and the product
    printf("Matrix 1:\n");
    displayMatrix(mat1);
    printf("Matrix 2:\n");
    displayMatrix(mat2);
    printf("Product of matrices:\n");
    displayMatrix(product);

    return 0;
}

/*
This program implements matrix multiplication using structures.
Each matrix has dimensions and elements.
The program allows the user to input the dimensions and elements of two matrices,
performs the matrix multiplication using a separate function, and then displays the resulting product matrix.
*/

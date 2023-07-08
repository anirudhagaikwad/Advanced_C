/*
Implement matrix multiplication in C using structures.

Example:
Enter the elements of the first matrix:
1 2 3
3 4 2
3 2 1
Enter the elements of the second matrix:
1 1 1
3 4 2
3 2 1
Result:
16 15 8
21 23 13
12 13 8
*/

#include <stdio.h>
#define N 3 //constant for matrix rows and cols

// Structure to represent a matrix
struct Matrix {
    int elements[N][N];
};

// Function to multiply two matrices and store the result in the given matrix
void multiply(struct Matrix a, struct Matrix b, struct Matrix* result) {
    // Perform matrix multiplication
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result->elements[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result->elements[i][j] += a.elements[i][k] * b.elements[k][j];
            }
        }
    }
}

int main() {
    struct Matrix matrix1, matrix2, result;

    // Input the elements of the first matrix
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix1.elements[i][j]);
        }
    }

    // Input the elements of the second matrix
    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix2.elements[i][j]);
        }
    }

    // Multiply the matrices
    multiply(matrix1, matrix2, &result);

    // Display the result
    printf("Result:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", result.elements[i][j]);
        }
        printf("\n");
    }

    return 0;
}


/*
In this updated program, the user is prompted to input the elements of the first matrix and the second matrix.
The matrices are stored in the matrix1 and matrix2 variables, respectively.

The multiply function is modified to take the matrices as input and store the result in the given matrix pointer result.
It performs matrix multiplication in the same way as before.

After the user inputs the matrices, the multiplication is performed by calling the multiply function with the input matrices
and the result matrix. Finally, the result matrix is displayed by iterating through its elements and printing them.

This program allows the user to input the matrices and performs matrix multiplication using structures in C.
*/


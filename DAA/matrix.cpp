#include <stdio.h>

// Function to multiply two matrices
void multiplyMatrices(int mat1[][3], int mat2[][3], int result[][3], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Function to display a matrix
void displayMatrix(int mat[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int mat2[][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    
    int rows1 = 3, cols1 = 3;
    int rows2 = 3, cols2 = 3;
    
    int result[3][3];
    
    multiplyMatrices(mat1, mat2, result, rows1, cols1, cols2);
    
    printf("Matrix 1:\n");
    displayMatrix(mat1, rows1, cols1);
    
    printf("\nMatrix 2:\n");
    displayMatrix(mat2, rows2, cols2);
    
    printf("\nMatrix Multiplication:\n");
    displayMatrix(result, rows1, cols2);
    
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

// Function to read a matrix from a file
int read_file(FILE *file, int ***matrix, int *rows, int *cols) {
    // Reading the number of rows and columns from the file
    fscanf(file, "%d %d", rows, cols);

    // Allocating memory for the matrix
    *matrix = (int **)malloc(*rows * sizeof(int *));
    for (int i = 0; i < *rows; i++) {
        (*matrix)[i] = (int *)malloc(*cols * sizeof(int));
    }

    // Reading matrix elements from the file
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            fscanf(file, "%d", &(*matrix)[i][j]);
        }
    }

    return 1; // Successful matrix read
}

// Function to free memory allocated for a matrix
void free_space(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to perform matrix addition
void addition(int **matrix1, int **matrix2, int **result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to print the elements of a matrix
void print_result(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to close the file
void close_file(FILE *file) {
    fclose(file);
}

int main(int argc, char *argv[]) {
    // Checking for the correct number of command-line arguments
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    // Opening the input file
    const char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Reading the number of test cases from the file
    int numTestCases;
    fscanf(file, "%d", &numTestCases);

    // Looping through each test case
    for (int testCase = 1; testCase <= numTestCases; testCase++) {
        int **matrix1, **matrix2, **result;
        int rows, cols;

        // Reading the first matrix from the file
        if (!read_file(file, &matrix1, &rows, &cols)) {
            close_file(file);
            return 1;
        }

        // Printing the first matrix
        printf("Test Case %d: 1st matrix:\n", testCase);
        print_result(matrix1, rows, cols);

        // Reading the second matrix from the file
        if (!read_file(file, &matrix2, &rows, &cols)) {
            close_file(file);
            free_space(matrix1, rows);
            return 1; // Error reading file
        }

        // Printing the second matrix
        printf("Test Case %d: 2nd matrix:\n", testCase);
        print_result(matrix2, rows, cols);

        // Allocating memory for the result matrix
        result = (int **)malloc(rows * sizeof(int *));
        for (int i = 0; i < rows; i++) {
            result[i] = (int *)malloc(cols * sizeof(int));
        }

        // Performing matrix addition
        addition(matrix1, matrix2, result, rows, cols);

        // Printing the result of matrix addition
        printf("\nTest Case %d: Result of matrix addition:\n", testCase);
        print_result(result, rows, cols);
        printf("\n");

        // Freeing memory for matrices
        free_space(matrix1, rows);
        free_space(matrix2, rows);
        free_space(result, rows);
    }

    // Closing the file
    close_file(file);

    return 0;
}

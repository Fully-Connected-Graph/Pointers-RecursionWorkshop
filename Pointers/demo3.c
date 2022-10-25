#include <stdio.h>
#include <stdlib.h>

/**
 * Performs safe memory allocation (ensures memory is allocated and exits with an error otherwise)
 * @param size The number of ints to be allocated
 * @return A dynamically allocated array (size-long) 
 */
int* safeMalloc(int size) {
    int *ptr = malloc(size*sizeof(int));
    if (ptr == NULL) {
        // throw error
        printf("Error!\n");
        exit(-1);
    }
    return ptr;
}

/**
 * Prints the given matrix
 * @param matrix The matrix to be printed
 * @param rows The number of rows of the matrix
 * @param cols The number of columns of the matrix
 */
void printMatrix(int** matrix, int rows, int cols){
    int row, col;
    printf("Printing the matrix\n");
    for (row = 0; row < rows; row++) {
        for (col = 0; col < cols; col++) {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }
}

/**
 * Duplicate a given array n times
 * @param array The array to be duplicated
 * @param arraySize The size of the array to be duplicated
 * @param n The number of times the array should be duplicated
 * @return A 2D array with the array duplicated n times
 */
int** duplicateIntArray(int* array, int arraySize, int n) {
    /**
     * Two parts to solving the problem
     * Part 1 - allocate memory
     * Part 2 - copy elements over
     */
    int **newArr;
    int row;
    int col;

	// allocate n number of int*
    newArr = malloc(n*sizeof(int*));
    // for each of these int*, allocate an array of the size - arraySize
    for (row=0; row<n; row++) {
        newArr[row] = safeMalloc(arraySize);
    }

    // fill in the matrix with values of n 
    for (row = 0; row < n; row++) {
        for (col = 0; col < arraySize; col++) {
            newArr[row][col] = array[col];
        }
    }
    return newArr;
}

/**
 * Frees the dynamically allocated 2D array
 * @param array The 2D array to be freed
 * @param height The number of rows in the 2D array
 */
void free2DArray(int** array, int height){
    int row;
    // Free the arrays
    for (row = 0; row < height; row++) {
        free(array[row]);
    }
    // Free the int*
    free(array);
}

int main(int argc, char **argv){
	
	// take input
	int arrSize;
    int n; 
    int i;
	scanf("%d %d\n", &arrSize, &n);
	int* arr = safeMalloc(arrSize);
	for(i=0; i<arrSize; i++) {
		scanf("%d", &arr[i]); 
	}
	
	int** duplicatedArr; 
	duplicatedArr = duplicateIntArray(arr, arrSize, n);
	printMatrix(duplicatedArr, n, arrSize);

	free2DArray(duplicatedArr, n);
	free(arr);
    
    // try to run this with valgrind to check if all the memory was freed 
    
	return 0;
}


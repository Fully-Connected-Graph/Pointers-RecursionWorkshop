#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void *safeMalloc(int n) {
    void *p = malloc(n);
    if (p == NULL) {
        printf("Error: malloc(%d) failed. Out of memory?\n", n);
    }
    return p;
}

/**
 * 
 * array - the array containing the data
 * index - the current index in the array
 * size - the size of the array
 * currentSum - the current sum of the recursion
 * max - the biggest current sum
 * sequenceLength - the number of consecutive numbers from the current sequence
*/
/**
 * In order to solve this exercise, you have to print the maximum sum of numbers, without considering
 * 3 or more consecutive elements. 
 * To do this, we have to make a recursion that starts from index 0, and in which either will consider a number,
 * and the sequence length will increase by 1 and the current sum will increase with the value of the element from
 * position index in the array, otherwise, the length of the sequence becomes 0 and the current sum stays unchanged.
 * We do this until the end of the array and at that moment we check if our current sum is bigger than our current max.
*/
void maxSum(int *array, int index, int size, int currentSum, int *max, int sequenceLength) {
    if(index >= size) {
        // base case
        // check if the current sun is bigger than the current max
        if(currentSum > *max) {
            *max = currentSum;
        }
        return;
    }

    // if our consecutive sequence is smaller than 2, we can consider the current element at the index location and
    // we update the sum and the length of the consecutive sequence.   
    if(sequenceLength < 2) {
        maxSum(array, index + 1, size, currentSum + array[index], max, sequenceLength+1);
    }

    // for this case, we don't consider the current element, so the current sum stays unchanged and the length of the
    // consecutive sequence will be changed to 0
    maxSum(array, index + 1, size, currentSum, max, 0);
}


/**
 * 
 * array - the array containing the data
 * lengthOfTheRemainedArray - the size of the array that still has to be checked
 * size - the size of the array
 * currentSum - the current sum of the recursion
 * max - the biggest current sum
 * sequenceLength - the number of consecutive numbers from the current sequence
*/
/**
 * This solution is doing the same thing as the solution presented earlier. The only difference is that
 * this time we use a variable that keeps track of the number of elements that still have to be checked.
*/
void maxSumDecreasingTheArray(int *array, int lengthOfTheRemainedArray, int size, int currentSum, int *max, int sequenceLength) {
    if(lengthOfTheRemainedArray < 0) {
        // base case
        // if there are no more elements to be checked, we stop
        // check if the current sun is bigger than the current max
        if(currentSum > *max) {
            *max = currentSum;
        }
        return;
    }

    // if our consecutive sequence is smaller than 2, we can consider the current element at the (size-lengthOfTheRemainedArray-1) location, we 
    // decrease the number of elements that still have to be checked and we update the sum and the length of the consecutive sequence.  
    if(sequenceLength < 2) {
        maxSumDecreasingTheArray(array, lengthOfTheRemainedArray - 1, size, currentSum + array[size - lengthOfTheRemainedArray - 1], max, sequenceLength+1);
    }

    // for this case, we don't consider the current element, so the current sum stays unchanged and the length of the
    // consecutive sequence will be changed to 0
    maxSumDecreasingTheArray(array, lengthOfTheRemainedArray - 1, size, currentSum, max, 0);
}


// Exam 2020

int main() {

    int size;

    scanf("%d:", &size);   
    
    int *array = safeMalloc(size*sizeof(int));
    
    for(int i=0;i<size;i++) {
        scanf("%d", &array[i]);
    }

    int max = -1;

    /**
     * This method uses an index to loop throught the array
    */
    maxSum(array, 0, size, 0, &max, 0);
    printf("%d\n", max);
    max = -1;
    /**
     * This method uses a variable that keeps track of the number of elements that still have to be checked.
    */
    maxSumDecreasingTheArray(array, size - 1, size, 0, &max, 0);
    printf("%d\n", max);

    free(array);
    return 0;
}
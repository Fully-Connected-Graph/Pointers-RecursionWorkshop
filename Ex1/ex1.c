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
 * length - the size of the array
 * array - the array containing the data
 * index - the current index in the array
 * target - the number to which our sum has to add to
 * sum - the current sum of our recursion
*/
/**
 * In order to solve this exercise, you have to calculate all the possible combinations in which you either                                 8
 * add or decrease the value of an element to a current sum. The order in which you perform these calculations must                      + / \ -        7
 * be the one in which you find the elements in the array.                                                                               15   1         
 * At the end, when there are no more numbers to be added or decreased, you check if the obtained sum is equal                         +/\- +/\-        2 
 * to a wanted target. In the end, what you have to do is to count the number of cases in which the sum obtained after                17 13 3  -1                   
 * each possible combination is equal to the target.                                                                                 /\  /\ /\  /\      3  
 * To keep in mind is that the first element from the list can't be negative, so at the moment in which you initialize the
 * current sum variable, you have to assign to it the value of the first element in the list. Besides this, when you start
 * trying the possibilities, you have to not consider again the first element of the array.
 * A partial recursion tree of this exercise is represented on the right for first input of this exercise.
*/

int rercursiveFunciontWithIndex(int length, int array[], int index, int target, int sum) {
    if (index == length) {
        // base case
        // In the case in which our index reached the length of the list, we stop our recursion, because there are no other elements
        // to be added or decreased.
        // Also, it means that we reached the moment in which we test if our sum adds is equal to the target.
        return (sum == target);
    }

    // sum + array[index] is for the case in which you add the value of the variable which is at index location
    // sum - array[index] is for the case in which you decrease the value of the variable which is at index location
    // The sum which is between these two calls is necessary because you want to count the number of favourable cases
    // and represents a possible method, in the case in which you want to use a variable to keep track of the favorible
    // cases.
    return rercursiveFunciontWithIndex(length, array, index + 1, target, sum + array[index]) +
           rercursiveFunciontWithIndex(length, array, index + 1, target, sum - array[index]);
}


/**
 * sizeOfTheArray - the size of the array
 * array - the array containing the data
 * sizeOfTheRemainedArray - the size of the array that we still have to check
 * target - the number to which our sum has to add to
 * sum - the current sum of our recursion
*/
/**
 * In order to solve this exercise, you have to calculate all the possible combinations in which you either                                 8
 * add or decrease the value of an element to a current sum. The order in which you perform these calculations must                      + / \ -        7
 * be the one in which you find the elements in the array.                                                                               15   1         
 * At the end, when there are no more numbers to be added or decreased, which means that the size of the remained array is             +/\- +/\-        2 
 * equal to zero, you check if the obtained sum is equal to a wanted target. In the end, what you have to do is to count              17 13 3  -1                   
 * the number of cases in which the sum obtained after each possible combination is equal to the target.                            /\  /\ /\  /\      3  
 * To keep in mind is that the first element from the list can't be negative, so at the moment in which you initialize the
 * current sum variable, you have to assign to it the value of the first element in the list. Besides this, when you start
 * trying the possibilities, you have to not consider again the first element of the array. To do this, you declare the initial size
 * of the remained array with the total number of elements minus 1. 
 * This function is doing the exact same thing as the one presented earlier, but the only difference is that this time we don't 
 * have an index that is starting at 1, but rather a variable that tells us how many elements we still have to check, which is 
 * of course initialised with the size of the initial array, and each time after we considered an element, we decrease the size of
 * the remained array.
 * A partial recursion tree of this exercise is represented on the right for first input of this exercise.
*/
int rercursiveFunciontWithDecresingTheSizeOfTheArray(int sizeOfTheArray, int array[], int sizeOfTheRemainedArray,int target, int sum) {
    if (sizeOfTheRemainedArray == 0) {
        return (sum == target);
    }

    // sum + array[sizeOfTheArray - sizeOfTheRemainedArray] is for the case in which you add the value of the variable which is at sizeOfTheArray - sizeOfTheRemainedArray location
    // sum - array[sizeOfTheArray - sizeOfTheRemainedArray] is for the case in which you decrease the value of the variable which is at sizeOfTheArray - sizeOfTheRemainedArray location
    // The sum which is between these two calls is necessary because you want to count the number of favourable cases
    // and represents a possible method, in the case in which you want to use a variable to keep track of the favorible
    // cases.
    // Also see that in this method, after each element that was considered, we decrease the size of the remained array that has to be tested. 
    return rercursiveFunciontWithDecresingTheSizeOfTheArray(sizeOfTheArray, array, sizeOfTheRemainedArray-1, target, sum + array[sizeOfTheArray - sizeOfTheRemainedArray]) +
           rercursiveFunciontWithDecresingTheSizeOfTheArray(sizeOfTheArray, array, sizeOfTheRemainedArray-1, target, sum - array[sizeOfTheArray - sizeOfTheRemainedArray]);
}

int helperFunction(int length, int a[], int target) {
/**
 * This is a recursive function in which you use an index starting from 1 to loop through the array. It starts from 1 because
 * our sum is already initialised with the first element of the array, since we know that this element can have just positive 
 * values and we don't need to test the case in which there is a minus in front of the first element. 
*/

    return rercursiveFunciontWithIndex(length, a, 1, target, a[0]); 

/**
 * This is a recursive function in which you use the size of the remained array as a way to loop in the array. 
 * It starts from length - 1, our sum is already initialised with the first element of the array, since we know that this element can have just positive 
 * values and we don't need to test the case in which there is a minus in front of the first element. 
*/

//    return rercursiveFunciontWithDecresingTheSizeOfTheArray(length, a, length - 1, target, a[0]);
}


// Exam 2015-12-01

int main() {

    int size, target;

    scanf("%d %d", &size, &target); 

    int *array = safeMalloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);  
    }

    printf("%d", helperFunction(size, array, target)); // call for the helper function and print the final result
    free(array);
    return 0;
}
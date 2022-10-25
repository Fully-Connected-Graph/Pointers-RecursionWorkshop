#include <stdio.h>

int main(int argc, char **argv){
	
    // declare a pointer
    int x = 0;
    int* ptr;

    // make a pointer point to something
    ptr = &x;
    
    // dereference the pointer 
    printf("The value stored at the address the pointer is pointing to - %d\n", *ptr);

    // change the value of the variable the pointer is pointing to
    *ptr = 42;
    printf("The value stored at the address the pointer is pointing to after changing the value - %d\n", *ptr);
    
    // sanity check - checking if the value of the variable has actually changed
    printf("Printing the new values of the variable - %d\n", x);
    
    
    printf("The old address - %p\n", (void*) ptr);
    // change the address that the pointer is pointing to
    int y = 2;
    ptr = &y;
    
    printf("The new address - %p\n", (void*) ptr);
    
	return 0;
}


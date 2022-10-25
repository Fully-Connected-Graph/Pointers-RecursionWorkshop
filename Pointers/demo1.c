#include <stdio.h>

int main(int argc, char **argv){
	
	// printing the address of the variable
    int x = 0;
    printf("Address the variable is stored at - %p\n", (void*)&x);

    // declare a pointer
    int* ptr;

    // make a pointer point to something
    ptr = &x;

    // printing the address that the pointer is pointing to
    printf("The address that the pointer is pointing to - %p\n", (void*)ptr);
    
    // notice that they are the same addresses
    
	return 0;
}


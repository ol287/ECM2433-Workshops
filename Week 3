// Question 1 -  prints out the parameters passed to it on the command line.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int i;
    for (i = 0; i < argc; i++)
        printf("Parameter %d: %s\n", i, argv[i]);

    if (argc > 1) {
        int value = atoi(argv[1]);
        if (value == 0 && argv[1][0] != '0') {
            printf("The first parameter '%s' is not a valid integer.\n", argv[1]);
        } else {
            printf("The first parameter as an integer is %d\n", value);
        }
    } else {
        printf("No parameters were passed to the program.\n");
    }

    return 0;
}

// Question 2 - Create a new program to do the following:
(a) Define an integer variable called x and initialise it with the value 4.
(b) Print out the value of x.
(c) Print out the memory address of where x is stored.
(d) Define xPtr as a pointer to x.
(e) Update the value of x to 6 using only xPtr.
(f) Print out the new value of x using only xPtr.
(g) Print out the memory address of where xPtr is stored.
Run this program several times; you will see that the memory addresses are not the same each time.


#include <stdio.h>

int main(){
    int x = 4;
    printf("Value of x: %d\n", x);
    printf("Memory address of x: %p\n", (void*)&x);
    int *xPtr;
    xPtr = &x;
    *xPtr = 6;
    printf("New value of x using xPtr: %d\n", *xPtr);
    printf("Memory address of xPtr: %p\n", (void*)&xPtr);
    return 0;
}

// Question 3 - Write a function called printInteger that takes a single integer as a parameter, adds 3 to it and then
prints out its value. The return type of the function should be the updated value of the integer. Call
your function like this:
int x = 42;
int y = 0;
printf("in main function x = %d, y = %d\n",x,y);
y = printInteger(x);
printf("in main function x = %d, y = %d\n",x,y);
The value of y should be 0 from the first printf and 45 from the second

// Question 4 - Write a function called printInteger that takes a single integer as a parameter, adds 3 to it and then
prints out its value

#include <stdio.h>

// Function prototype declaration
int printInteger(int);

int main() {
    int x = 42;
    int y = 0;
    
    printf("in main function x = %d, y = %d\n", x, y);
    
    // Call the printInteger function and store its return value in y
    y = printInteger(x);
    
    printf("in main function x = %d, y = %d\n", x, y);
    
    return 0;
}

// Function definition
int printInteger(int num) {
    // Add 3 to the input integer
    num += 3;
    
    // Print the updated value
    printf("Inside printInteger function, num = %d\n", num);
    
    // Return the updated value
    return num;
}

// Question 5 - write a function to increment an interger by 3


#include <stdio.h>

void updateInteger(int *ptr) {
    *ptr += 3;
}

int main() {
    int x = 42;
    printf("in main function x = %d\n", x);
    updateInteger(&x);
    printf("in main function x = %d\n", x);

    return 0;
}

// Question 6 - Write a program that expects an integer value to be passed as a command line parameter and then
creates an array to hold exactly that number of short int values (hint: use the malloc function).
Populate the array with the numbers from 1 to the number entered and then print them out. For
example if your program executable is called myProgram, then running it using the command
myProgram 3
should cause an array of size 3 to be created, containing the values 1, 2 and 3. Remember to explicitly
free the memory before your program closes.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <size_of_array>\n", argv[0]);
        return 1;
    }

    int size = atoi(argv[1]); // Convert the command line argument to an integer

    if (size <= 0) {
        printf("Please enter a positive integer as the size of the array.\n");
        return 1;
    }

    short int *arr = (short int *)malloc(size * sizeof(short int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int i;
    for (i = 0; i < size; i++) {
        arr[i] = i + 1;
    }

    printf("Array of size %d containing values from 1 to %d:\n", size, size);

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}



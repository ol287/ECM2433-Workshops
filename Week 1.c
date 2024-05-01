// question 1

// defines a macro
//replaces the header line with the contents of stdio.h
//preprocess looks in the file path it expects to find the stdio.h in
#include <stdio.h>

//by convention main is always at the top
// must always return 0
int main() {
    //sends an ouput to stdout stream
    printf("Hello, World!\n");
    return 0;
}

// question 2

#include <stdio.h>

int main() {
    
    //short int size 2 bytes
    unsigned short int x = 1;
    short int y = 65535;

    //char size is one byte
    unsigned char c = 'A';

    //sends an output to stdout
    printf("x has the value %hu\n", x);
    printf("y has the value %d\n", y);
    printf("c has the value %c\n", c);

    return 0;
}

// question 3A

#include <stdio.h>

int main() {
    int i;
    for (i = 1; i <= 20; i++) {
        //remainder
        if (i % 2 == 0) {
            printf("%d\n", i);
        }
    }
    return 0;
}

// question 3B

#include <stdio.h>

int main() {
    int i = 1;
    while (i <= 20) {
        if (i % 2 == 0) {
            printf("%d\n", i);
        }
        //increment
        i++;
    }
    return 0;
}

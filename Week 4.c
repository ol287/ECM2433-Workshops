//Question 1 - Create a C program that reads in a simple text file containing two comma-separated integers on each
//line (imagine these as two columns of numbers) and outputs the sum of the integers in each column.
//The file contents might be like this:
//123,5
//1,296
//64,99
//And the output will be 188 (i.e. 123+1+64) and 400 (i.e. 5+296+99). Do not worry about the format of
//the output. The program must take in the name of the file from the command line. Don’t forget to trap
//the usual errors. What happens to your program if the following “normal” things happen:
//• No file name is passed to the program.
//• The file specified does not exist.
//• The file is empty.
//• The file does not have the expected format.



#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    //argc stores the number of arguments passed to the program on the command line
    // Check if a file name is passed
    if (argc < 2) {
        printf("No file name was passed to the program.\n");
        return 1;
    }

    // Open the file
    //* is a pointer to the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("The file specified does not exist.\n");
        return 1;
    }

    int sum1 = 0, sum2 = 0, num1, num2;
    char comma;
    int result;
    while ((result = fscanf(file, "%d%c%d", &num1, &comma, &num2)) != EOF) {
        //EOF means end of file
        if (result != 3 || comma != ',') {
            //should be 3 values on the line: 2 intergers and one comma
            printf("The file does not have the expected format.\n");
            fclose(file);
            return 1;
        }
        sum1 += num1;
        sum2 += num2;
    }

    // Check if the file is empty
    if (feof(file) && sum1 == 0 && sum2 == 0) {
        printf("The file is empty.\n");
        fclose(file);
        return 1;
    }

    // Output the sums
    printf("%d,%d\n", sum1, sum2);

    // Close the file
    fclose(file);

    return 0;
}

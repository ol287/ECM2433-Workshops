#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

//preprocessor macros that define indices used to access the read and write ends of a pipe, respectively.
//define macros for subsitution
#define READ_END 0
#define WRITE_END 1

//funciton defintions
// both functions return nothing
// both functions take an array of intergers
void parent_process(int pipe_fd[]);
void child_process(int pipe_fd[]);

int main() {
    //declares an array of size 2
    int pipe_fd[2];

    //checks if the pipe creation failed
    
    if (pipe(pipe_fd) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    //Forking the process to create a child process.
    //fork function will return the childprocess id
    pid_t pid = fork();

    //checks if the fork failed
    if (pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        //sends the chlid process id to the oarent
        parent_process(pipe_fd);
    } else {
        // Child process
        child_process(pipe_fd);
    }

    return 0;
}

//function to be executed by the parent process
void parent_process(int pipe_fd[]) {

    // Close unused read end
    close(pipe_fd[READ_END]);  

    //Seeding the random number generator with the current time to generate random numbers later.
    srand(time(NULL));

    //Infinite loop to send random numbers to the child process.
    while (1) {
        int random_num = rand() % 10;
        printf("Parent: send wait %d\n", random_num);
        write(pipe_fd[WRITE_END], &random_num, sizeof(int));

        //The parent process reads from the pipe for a response from the child process.
        char response;
        read(pipe_fd[READ_END], &response, sizeof(char));
        if (response == 'Z') {
            continue;
        }
    }
}

void child_process(int pipe_fd[]) {

    // Close unused write end
    close(pipe_fd[WRITE_END]);  

    //Ignore the SIGUSR1 signal
    signal(SIGUSR1, SIG_IGN);  

    //Infinite loop to read from the pipe and process the received numbers.
    while (1) {
        int received_num;
        read(pipe_fd[READ_END], &received_num, sizeof(int));

        //If the received input is a number, the child process prints messages, 
        //sleeps for a specified duration, and sends a response back to the parent process. 
        //If the received input is 'X', the child process terminates.
        if (received_num >= 0 && received_num <= 9) {
            printf("Child: started %d\n", received_num);
            sleep(received_num);
            printf("Child: completed %d\n", received_num);
            write(pipe_fd[WRITE_END], "Z", sizeof(char));
        } else if (received_num == 'X') {
            printf("Child: stopped.\n");
            break;
        }
    }
}

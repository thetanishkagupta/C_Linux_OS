#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
 
int main() {
    pid_t pid1, pid2, pid3;
 
    // Fork a child process
    pid1 = fork();
 
    if (pid1 < 0) {
        // Fork failed
        perror("Fork 1 failed");
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {
        // Child process 1
        printf("Child 1 (PID: %d) executing sleep for 3 seconds...\n", getpid());
        sleep(3);
        printf("Child 1 (PID: %d) done sleeping.\n", getpid());
        exit(EXIT_SUCCESS);
    }
 
    // Fork another child process
    pid2 = fork();
 
    if (pid2 < 0) {
        // Fork failed
        perror("Fork 2 failed");
        exit(EXIT_FAILURE);
    } else if (pid2 == 0) {
        // Child process 2
        printf("Child 2 (PID: %d) executing ls -l...\n", getpid());
        execl("/bin/ls", "ls", "-l", NULL);
        perror("Exec 2 failed");
        exit(EXIT_FAILURE);
    }
 
    // Fork yet another child process
    pid3 = fork();
 
    if (pid3 < 0) {
        // Fork failed
        perror("Fork 3 failed");
        exit(EXIT_FAILURE);
    } else if (pid3 == 0) {
        // Child process 3
        printf("Child 3 (PID: %d) executing date command...\n", getpid());
        execl("/bin/date", "date", NULL);
        perror("Exec 3 failed");
        exit(EXIT_FAILURE);
    }
 
    // Parent process
    printf("Parent (PID: %d) waiting for child processes to complete...\n", getpid());
    wait(NULL);
    wait(NULL);
    wait(NULL);
 
    printf("All child processes completed. Parent exiting.\n");
 
    return 0;
}

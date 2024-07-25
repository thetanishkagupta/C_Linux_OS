#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    pid_t pid;
    int status;

    pid = vfork(); // Using vfork() instead of fork()

    if(pid == -1) {
        perror("vfork"); // Error handling if vfork fails
        exit(EXIT_FAILURE);
    }
    else if(pid == 0) {
        printf("It is the child process and pid is %d\n", getpid());
        _exit(EXIT_SUCCESS); // Terminate the child process
    }
    else {
        printf("It is the parent process and pid is %d\n", getpid());
        wait(&status); // Parent waits for the child to complete
        printf("Child process (PID: %d) has completed\n", pid);
    }

    return 0;
}


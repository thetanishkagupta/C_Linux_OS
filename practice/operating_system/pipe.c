#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];  

    if (pipe(fd) == -1) {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

   
    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        close(fd[1]); 
        char buffer[100];
        int read_bytes = read(fd[0], buffer, sizeof(buffer));
        if(read_bytes <= 0)
        {
            printf("buffer is empty, can't read anything\n");
            close(fd[0]);
            exit(1);
        }
        printf("Child received: %s\n", buffer);
        close(fd[0]);  
       
   } else {

        close(fd[0]);  
        char message[100];
        printf("Enter the message : ");
        fgets(message, sizeof(message), stdin);

        if(strcmp(message , "\n") == 0)
        {
            printf("Buffer is empty, Please write something\n");
            close(fd[1]);
            exit(1);
        }
        int write_bytes = write(fd[1], message, sizeof(message));
        if (write_bytes <= 0)
            perror("No message , write something\n");
        close(fd[1]); 
    }

    return 0;
}


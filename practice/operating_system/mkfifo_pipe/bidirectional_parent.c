#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUF_SIZE 300

int main()
{
    int pd[2];
    int fd[2];
    char buffer[BUF_SIZE];

    if (pipe(pd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    mkfifo("sender_to_receiver", 0666);
    mkfifo("receiver_to_sender", 0666);

    fd[1] = open("sender_to_receiver", O_WRONLY);
    fd[2] = open("receiver_to_sender", O_RDONLY);

    while(1)
    {
        printf("Enter text: ");
        fgets(buffer, BUF_SIZE, stdin);

        write(fd[1], buffer, strlen(buffer)+1);
        read(fd[2], buffer, BUF_SIZE);

        printf("Received from receiver: %s", buffer);
    }

    close(fd[1]);
    close(fd[2]);

    close(pd[0]);
    close(pd[1]);

    return 0;
}


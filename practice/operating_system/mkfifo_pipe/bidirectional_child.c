#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUF_SIZE 300

int main()
{
    int pd[2];
    int fd[2];
    char buffer[BUF_SIZE];

    if(pipe(pd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    mkfifo("sender_to_receiver", 0666);
    mkfifo("receiver_to_sender", 0666);

    fd[1] = open("sender_to_receiver", O_RDONLY);
    fd[2] = open("receiver_to_sender", O_WRONLY);

    while(1)
    {
        read(fd[1], buffer, BUF_SIZE);

        for(int i = 0; buffer[i]; i++)
        {
            buffer[i] = toupper(buffer[i]);
        }
        write(fd[2], buffer, strlen(buffer)+1);
    }
    close(fd[1]);
    close(fd[2]);

    close(pd[0]);
    close(pd[1]);

    return 0;
}


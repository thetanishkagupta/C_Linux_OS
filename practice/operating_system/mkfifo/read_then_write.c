#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    int fd1;
    char *fifo = "fifo_file";

    mkfifo(fifo, 0666);

    char str1[100], str2[100];
    while(1)
    {
        fd1 = open(fifo, O_RDONLY);
        read(fd1, str1, 100);
        printf("User 1 : %s\n", str1);
        close(fd1);

        fd1 = open(fifo, O_WRONLY);
        fgets(str2, 100, stdin);
        write(fd1, str2, strlen(str2)+1);
        close(fd1);
    }
    return 0;
}



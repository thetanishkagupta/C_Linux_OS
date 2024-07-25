#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
    int fd, n;
    fd = open("fifo1", O_WRONLY);
    write(fd,"Hi from parent to child", 24);
    printf("Sender process having PID %d sent the data into pipe fifo1\n", getpid());
}


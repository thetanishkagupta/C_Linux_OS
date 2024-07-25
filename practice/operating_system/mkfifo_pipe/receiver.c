#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
    int fd, n;
    char buffer[100];
    fd = open("fifo1", O_RDONLY);
    n = read(fd, buffer, 100);
    printf("Child process having PID %d started\n", getpid());
    printf("Data received by receiver from sender %d is: %s\n", getpid(), buffer);
}




#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>

int errno;

int main()
{
    int fd = open("file1.txt", O_RDWR);

    printf("%d\n", fd);
    if(fd < 0)
    {
        printf("error no. %d\n", errno);
    perror("");
    }
    return 0;
}

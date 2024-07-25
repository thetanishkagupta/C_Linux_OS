#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>

int main(void)
{
    char buf[50];
    int fd;

    fd = open("insert.txt", O_RDWR);

   // read(0, buf, 50);   to read from user
    //write(fd, buf, 50); to write in file

    read(fd, buf, 6); // after writing read particular bytes from file
    printf("%s", buf);   
    
    close(fd);

    return 0;
}


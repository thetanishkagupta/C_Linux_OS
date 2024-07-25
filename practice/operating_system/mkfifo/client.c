#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
 
#define FIFO_FILE "client_server_fifo"
 
int main(void)
{
    int fd;
    char readbuf[100];
    char writebuf[100];
 
    fd = open(FIFO_FILE, O_RDWR);
    if (fd < 0)
    {
        perror("Error opening FIFO\n");
        exit(1);
    }
 
    printf("Enter the message for server..\n");
    fgets(writebuf, sizeof(writebuf), stdin);
    if (strcmp(writebuf, "\n") == 0)
    {
        printf("Buffer is empty");
    }

    int write_bytes = write(fd, writebuf, sizeof(writebuf));
    if (write_bytes == -1)
    {
        perror("Buffer is empty, write something\n");
        close(fd);
        exit(1);
    }
 
    read(fd, readbuf, sizeof(readbuf));
    printf("Received message from server: %s\n", readbuf);
  
    close(fd);
    return 0;
 
}

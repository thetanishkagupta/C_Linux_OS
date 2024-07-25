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
    
    mkfifo(FIFO_FILE, 0666);
 
    printf("Server waiting for client....\n");
    fd = open(FIFO_FILE, O_RDWR);
    if (fd < 0)
    {
        printf("Error opening FIFO\n");
        exit(1);
    }
 
    int read_bytes = read(fd, readbuf, sizeof(readbuf));
    if (read_bytes < 0)
    {
        printf("Buffer is empty\n");
        close(fd);
        exit(1);
    }
    printf("Received message: %s\n", readbuf);
 
    printf("Enter message to send to client: ");
    fgets(writebuf, sizeof(writebuf), stdin);
    if (strcmp(writebuf, "\n") == 0)
    {
        printf("Buffer is empty");
        exit(1);
    }

    write(fd, writebuf, sizeof(writebuf));
 
    close(fd);
    return 0;
 
}

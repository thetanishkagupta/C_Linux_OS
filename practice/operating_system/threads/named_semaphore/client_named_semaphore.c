#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <semaphore.h>

#define FIFO_FILE "myfifo"
#define SEM_NAME "/named_semaphore"

int main(void)
{
    int fd;
    char read_buf[100];
    char write_buf[100];

    //open the named semaphore
    sem_t *sem = sem_open(SEM_NAME, O_CREAT, 0666, 0);  //initialize to 0
    if (sem == SEM_FAILED)
    {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    fd = open(FIFO_FILE, O_RDWR);
    if (fd == -1)
    {
        printf("Error opening FIFO\n");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Enter the message for server.....\n");
    fgets(write_buf, sizeof(write_buf), stdin);

    int write_bytes = write(fd, write_buf, strlen(write_buf) + 1);
    if (write_bytes == -1)
    {
        printf("Error writing in FIFO\n ");
        close(fd);
        exit(EXIT_FAILURE);
    }

    sem_post(sem);  //Release the sempahore (unlock)
    //wait for semaphore (lock)

    sem_wait(sem);

    int read_bytes = read(fd, read_buf, sizeof(read_buf));
    if(read_bytes == -1)
    {
        printf("Error reading from FIFO\n ");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Received message from server : %s\n", read_buf);

    //Release the semaphore (unlock)
    sem_post(sem);

    close(fd);
    sem_close(sem);

    return 0;
}









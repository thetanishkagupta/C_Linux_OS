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

    //create / open the named sempahore
    sem_t *sem = sem_open(SEM_NAME, O_CREAT, 0666, 0); // initialized to 0
    if(sem == SEM_FAILED)
    {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    mkfifo(FIFO_FILE, 0666);

    printf("Server waiting for client.....\n");
    fd = open(FIFO_FILE, O_RDWR);
    if (fd == -1)
    {
        printf("Error in opening FIFO\n");
        close(fd);
        exit(EXIT_FAILURE);
    }

    //wait for semaphore (LOCK)
    sem_wait(sem);

    int read_bytes = read(fd,  read_buf, sizeof(read_buf));
    if(read_bytes == -1);
    {
        printf("Read error\n");
        close(fd);
        exit(EXIT_FAILURE);
    }

    sem_post(sem);  //Release the semaphore (unlock)
    printf("Received message from client: %s\n", read_buf);

    printf("Enter message to send to client : ");
    fgets(write_buf, sizeof(write_buf), stdin);

    int write_bytes = write(fd, write_buf, strlen(write_buf) + 1);
    if (write_bytes == -1)
    {
        printf("Write error\n");
        close(fd);
        exit(EXIT_FAILURE);
    }

    //Release the semaphore (unlock)
    sem_post(sem);

    close(fd);
    sem_close(sem);
    sem_unlink(SEM_NAME);  //unlink the named semaphore

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
 
#define QUEUE_NAME "/my_message_queue"
#define MAX_MSG_SIZE 256
#define MSG_BUFFER_SIZE (MAX_MSG_SIZE + 1)
 
int main() {
    mqd_t mq;
    struct mq_attr attr;
    char buffer[MSG_BUFFER_SIZE];
    int msg_priority = 1; 
 
    // Set attributes for the message queue
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10; // Maximum number of messages in the queue
    attr.mq_msgsize = MAX_MSG_SIZE; // Maximum size of each message
    
 
    
    mq = mq_open(QUEUE_NAME, O_CREAT | O_WRONLY, 0644, &attr);
    if (mq == -1) {
        perror("mq_open");
        exit(1);
    }
 
 
    printf("Enter message to send: ");
    fgets(buffer, MSG_BUFFER_SIZE, stdin);
    mq_send(mq, buffer, strlen(buffer), msg_priority);
 
    
    mq_close(mq);
 
    
    mq = mq_open(QUEUE_NAME, O_RDONLY);
    if (mq == -1) {
        perror("mq_open");
        exit(1);
    }
 
    
    ssize_t bytes_read = mq_receive(mq, buffer, MSG_BUFFER_SIZE, NULL);
    if (bytes_read >= 0) {
        buffer[bytes_read] = '\0'; 
        printf("Received message: %s\n", buffer);
    } else {
        perror("mq_receive");
    }
 
    
    mq_close(mq);
 
 
    mq_unlink(QUEUE_NAME);
 
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;

void *print_message_function1(void *ptr);
void *print_message_function2(void *ptr);

int main()
{
     pthread_t thread1, thread2;
     char *message1 = "Thread 1";
     char *message2 = "Thread 2";
     int  iret1, iret2;

    // Initialize sempahore with initial value 0
     if(sem_init(&semaphore, 0, 0)!= 0)
     {
         perror("sem_init");
         exit(EXIT_FAILURE);
     }

     //create threads
     iret1 = pthread_create( &thread1, NULL, print_message_function1, (void*) message1);
     iret2 = pthread_create( &thread2, NULL, print_message_function2, (void*) message2);

     // Wait till threads are complete before main continues.

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 

     printf("Thread 1 returns: %d\n",iret1);
     printf("Thread 2 returns: %d\n",iret2);

     //Destroy the semaphore
     sem_destroy(&semaphore);

     exit(0);
}

void *print_message_function1( void *ptr )
{
     char *message;
     message = (char *) ptr;
     printf("%s \n", message);

     //Signal the semaphore to unblock the next thread
     sem_post(&semaphore);
     pthread_exit(NULL);
}

void *print_message_function2(void *ptr)
{
    char *message;
    message = (char *)ptr;

    //wait until the semaphore is signaled (unblocked)
    sem_wait(&semaphore);
    printf("%s \n", message);
    pthread_exit(NULL);
}







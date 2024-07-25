#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
 
int sum = 0, avg = 0;
sem_t semaphore;
 
static void *thread_sum(void *arg) {
    for (int i = 0; i < 1024; i++) {
        sum += i;
    }
 
    // Signal that thread_sum has finished calculating the sum
    sem_post(&semaphore);
    pthread_exit(NULL);
}
 
static void *thread_avg(void *arg) {
    // Wait for thread_sum to finish calculating the sum
    sem_wait(&semaphore);
 
    avg = sum / 1024;
    pthread_exit(NULL);
}
 
int main() {
    pthread_t tid_sum, tid_avg;
    int status_sum, status_avg;
 
    // Initialize the semaphore with initial value 0
    if (sem_init(&semaphore, 0, 0) != 0) {
        perror("sem_init");
        exit(EXIT_FAILURE);
    }
 
    printf("Main process started\n");
 
    // Create threads
    status_sum = pthread_create(&tid_sum, NULL, &thread_sum, NULL);
    status_avg = pthread_create(&tid_avg, NULL, &thread_avg, NULL);
 
    if (status_sum != 0 || status_avg != 0) {
        fprintf(stderr, "Error creating threads\n");
        exit(EXIT_FAILURE);
    }
 
    // Wait for threads to complete
    pthread_join(tid_sum, NULL);
    pthread_join(tid_avg, NULL);
 
    printf("Main process: sum = %d, avg = %d\n", sum, avg);
    printf("Main process exiting\n");
 
    // Destroy the semaphore
    sem_destroy(&semaphore);
 
    return 0;
}

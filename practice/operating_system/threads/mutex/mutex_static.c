#include <pthread.h>
#include <stdio.h>
 
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int shared_resource = 0;
 
void* thread_function(void* arg) {
    int thread_id = *((int*)arg);
 
    // Acquire the mutex lock
    pthread_mutex_lock(&mutex);
    // Increment the shared resource
    shared_resource++;
    printf("Thread %d incremented shared resource to %d\n", thread_id, shared_resource);
 
    // Release the mutex lock
    pthread_mutex_unlock(&mutex);
 
    return NULL;
}
 
int main() {
    pthread_t threads[5];
    int thread_args[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i) {
        // Create threads with the thread ID as the argument
        pthread_create(&threads[i], NULL, thread_function, &thread_args[i]);
        // Ensure that the threads are created in order
        pthread_join(threads[i], NULL);
    }
 
    // All threads have completed here
    pthread_mutex_destroy(&mutex);
    return 0;
}



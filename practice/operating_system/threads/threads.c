#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
 

static void *thread_sum(void *arg)
{
  int i;
  int *sum = malloc(sizeof(int));
  printf("thread started\n");
  //sleep(2);
  *sum = 0;
  for (i = 0; i < 1024; i++)
    *sum += i;
  printf("thread exit\n");
  pthread_exit(sum);
}
 
#define handle_error_en(en, msg) \
               do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)
 
int main()
{
  pthread_t tid;
  int status;
  void *res;
  printf("main process started\n");
  status = pthread_create(&tid, NULL, &thread_sum, NULL);
  if (status != 0)
    handle_error_en(status, "pthread_create");
 
  //sleep(5);
  pthread_join(tid, &res);
  printf("main process: sum = %d\n", *((int *)res));
  printf("main process exiting\n");
  return 0;
}

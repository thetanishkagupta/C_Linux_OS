#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define handle_error_en(en, msg) \
               do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

int sum, avg = 0;
 
static void *thread_sum(void *arg)
{
  int i;
  for (i = 0; i < 1024; i++)
    sum += i;
}
 
static void *thread_avg(void *arg)
{
        avg = sum/1024;
}
 
int main()
{
  pthread_t tid_sum, tid_avg;
  int status_sum, status_avg;
  void *res;
  void *re;
  printf("main process started\n");
  status_sum = pthread_create(&tid_sum, NULL, &thread_sum, NULL);
  status_avg = pthread_create(&tid_avg, NULL, &thread_avg, NULL);
  if (status_sum != 0 || status_avg != 0)
    handle_error_en(status_sum, "pthread_create");
 
  pthread_join(tid_sum, &res);
  pthread_join(tid_avg, &re);
 
  printf("main process: sum = %d\n avg = %d\n", sum, avg);
  printf("main process exiting\n");
 
  return 0;
}

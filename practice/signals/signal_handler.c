#include <stdio.h>
#include <signal.h>

void my_handler(int signo)
{
    printf("Signal caught is %d", signo);
}

int main()
{
    signal(SIGINT, my_handler);
    while(1)
    {
        printf("Hello world\n");
        sleep(1);
    }
    return 0;
}


#include <stdio.h>
#include <signal.h>

int main(void)
{
    signal(SIGINT, SIG_IGN);
    while(1)
    {
        printf("Don't sleep\n");
    }
    return 0;
}


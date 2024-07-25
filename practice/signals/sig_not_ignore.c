#include <stdio.h>
#include <signal.h>
int main(void)
{
    signal(SIGKILL, SIG_IGN);
    while(1)
    {
        printf("Don't sleep \n");
    }
    return 0;
}


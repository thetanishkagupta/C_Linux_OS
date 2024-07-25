#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>

void function();

int main(void)
{
    atexit(function);

    printf("This is main\n");
    //exit(0);
    _exit(0);

    printf("Line after exit\n");
    return 0;
}

void function()
{
    printf("This is function\n");
}


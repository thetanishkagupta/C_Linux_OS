#include <stdio.h>

int main()
{
    int x = 0;
    if(++x, x=x+2, x>5)
    {
        printf("Hello\n");
    }    
    else
        printf("He\n");
    printf("x=%d\n",x);    
    
}

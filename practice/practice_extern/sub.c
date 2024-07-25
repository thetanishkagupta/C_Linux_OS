#include<stdio.h>          
extern int addition(int a, int b);
void subtraction(int a, int b) 
{
    int add=addition(a,b);
    printf("%d",add);
    printf("Result: %d\n", a - b);
}

      

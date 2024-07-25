#include<stdio.h>
int main()
{
    char *a[19];
    char *b[] = {"head", "art"};
    printf("the size is : %ld\n", sizeof(a));
    printf("the size is : %ld\n", sizeof(b));
    return 0;
    }

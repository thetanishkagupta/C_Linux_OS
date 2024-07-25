#include<stdio.h>
int main(int argc, char *argv[])
{
    int i;
    int count = 0;
    int ch = 'a';
    printf("You have entered %d arguments:\n", argc-1);
    for(i = 1;i < argc; i++)
    {
        while(*argv[i] != '\0')
        {
            if (*argv[i] == ch)
                count++;
            argv[i]++; 
        }
    }
    printf(" the count of 'a' is : %d", count);
    return 0;
}


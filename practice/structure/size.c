#include <stdio.h>

typedef struct size{
    int a:32;
    short b:5;
    short c:2;
    char d:1;
}type;

int main()
{
    type var;
    printf("size of structure is: %ld\n", sizeof(var));

    return 0;
}

 

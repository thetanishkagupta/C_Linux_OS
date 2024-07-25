#include<stdio.h>
int main()
{
    char a[][4] = {{'a','b','c','d'},
                   {'e','f','g','h'},
                   {'i','j','k','l'}};
    //printf("%s %s %s",a[0], a[1], a[2]);
    //printf("%s %s %s",*(a+0), *(a+1), *(a+2));
    //printf("%p\n %p\n %p\n ", &a[0], &a[1], &a[2]);
    //printf("%p\n %p\n %p\n ", &a[0]+1, &a[1]+1, &a[2]+1);
    printf("%p\n", &a);
    printf("%p\n", &a+1);
    return 0;
}


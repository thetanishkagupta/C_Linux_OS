#include<stdio.h>

void copy(char *src, char *dest);

int main()
{
    char src[] = "hello";
    char dst[10];
    copy(src,dst);
    printf("%s", dst);
    //printf("%c %c", dest[2], dest[3]);
    return 0;
}






#include <stdio.h>
#include <string.h>
#define MAX 100
void my_strncat(char*, char*, int);

int main()
{
    char src[MAX];
    char dest[MAX];
    int n;
    printf("Enter the source string : ");
    fgets(src, MAX, stdin);

    int s_len = strlen(src);
    src[s_len -1] = '\0';

    printf("Enter the destination string : ");
    fgets(dest, MAX, stdin);

    int d_len = strlen(dest);
    dest[d_len -1] = '\0';

    printf("Enter the no of character : ");
    scanf("%d", &n);

    my_strncat(dest,src,n);
    printf("the updated string is : %s\n", dest);
    return 0;
}

void my_strncat(char *dest, char *src, int n)
{
    int len = strlen(dest);
    dest = dest + len;
    while (*src != '\0' && n != 0)
    {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    *dest = '\0';
}




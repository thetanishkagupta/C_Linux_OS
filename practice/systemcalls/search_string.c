#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX 100

int main()
{
    char str[MAX];
    printf("enter the string: ");
    fgets(str, MAX, stdin);
    int len = strlen(str);
    str[len-1] = '\0';

    char buf[MAX];

    FILE *fp;

    fp = fopen("input.txt", "r");
    int count = 0;
    while(fgets(buf, MAX, fp) != NULL)
    {
        count ++;
        if(strstr(buf, str))
        {
            printf("The line is : %s\n", buf);
            printf("line number is %d", count);
        }
        printf("\n");
    }
    fclose(fp);
    return 0;
}


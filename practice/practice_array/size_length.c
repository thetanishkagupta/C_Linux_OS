#include<stdio.h>
#include<string.h>
#define SIZE 20
int main()
{
    char str1[SIZE] = "Capgemini";
    char str2[] = "Capgemini";
    char *str3 = "Capgemini";
 
    printf("the string1 len and size is: %ld and %ld\n", strlen(str1), sizeof(str1));
    printf("the string2 len and size is: %ld and %ld\n", strlen(str2), sizeof(str2));
    printf("the string3 len and size is: %ld and %ld\n", strlen(str3), sizeof(str3));

    str1[1] = 'z';
    str2[1] = 'y';
    *(str3 + 1) = 'x';
    printf("%s %s %s", str1, str2, str3);

    return 0;
}


#include<stdio.h>
#include<string.h>
#define SIZE 20
 
int frequency(char *str, char ch);
 
int main(void)
{
    char str[SIZE];
    char ch;
    printf("Enter the string: \n");
    scanf("%s", str);
    printf("Enter the char: \n");
    scanf("\n");
    scanf(" %c", &ch);
 
    printf("The count of %c is %d: ", ch, frequency(str, ch));
    return 0;
 
}
 
int frequency(char *str, char ch)
{
    int count;
    count = 0;
    while(*str != '\0')
    {
        if(*str == ch)
            count++;
        str++;
    }
    return count;
}

 
 

#include<stdio.h>
#include<string.h>
#define SIZE 20
 
void shift(char *str, int pos);
 
int main(void)
{
    char str[SIZE];
    printf("Enter the string: \n");
    scanf("%s", str);
    int pos;
    printf("Enter the position: \n");
    scanf(" %d", &pos);
 
    shift(str, pos);
    printf("Updated String is: %s\n", str);
 
    return 0;
 
}
 
void shift(char *str, int pos)
{
    int i;
    i = pos-1;
    while(*(str+i) != '\0')
    {
        *(str+i) = *(str+i+1);
        i++;
    }
}

 
 

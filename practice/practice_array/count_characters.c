#include<stdio.h>
#define MAX 100
 
int isAlpha(char);
int isDigit(char);
int isSpace(char);
 
int main(int argc, char *argv[])
{
    char *str = argv[1];
    /*
        char str[MAX];
        printf("Enter a string: \n");
        scanf("%[^\n]",str);
        */
        int i = 0, alpha = 0, digit = 0, space = 0;
        while(str[i]!='\0')
        {
//              printf("%c\n",str[i]);
                if(isAlpha(str[i])){
                        alpha++;
                //      printf("%d %c\n",alpha, str[i]);
                }
                else if(isDigit(str[i]))
                        digit++;
                else if(isSpace(str[i]))
                        space++;
 
                i++;
        }
 
        printf("Number of Alphabets: %d\nNumber of Digits: %d\nNumber of Space: %d\n", alpha, digit, space);
        return 0;
}
int isAlpha(char ch)
{
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
                return 1;
 
        return 0;
}
 
int isDigit(char ch)
{
        if(ch >= '0' && ch <= '9')
                return 1;
 
        return 0;
}
 
int isSpace(char ch)
{
        if(ch == ' ')
                return 1;
 
        return 0;
}

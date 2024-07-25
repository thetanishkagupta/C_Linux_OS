#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

int main()
{
    FILE *fp;
    char ch;

    fp = fopen("upper.txt" , "r+");
    if (fp == NULL)
    {
        perror(" File does not exist " );
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (isupper(ch))
        {
            ch = tolower(ch);
            fseek(fp, -1, SEEK_CUR);
            fputc(ch, fp);
        }
    }
    fclose(fp);
    //printf("Conversion done to %s\n", fp);
    return 0;
}





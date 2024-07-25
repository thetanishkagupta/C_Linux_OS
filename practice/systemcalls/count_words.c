#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    FILE *fp;
    char str[MAX];
    char *word;
    int count = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("File does not exist");
        return 1;
    }

    while(fgets(str, MAX, fp) != NULL)
    {
        word = strtok(str, " ");
        while(word != NULL)
        {
            count ++;
            word = strtok(NULL, " ");
        }
    }
    fclose(fp);
    printf("Number of words in the given file is: %d\n", count);
    return 0;
}

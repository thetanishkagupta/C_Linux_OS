#include <stdio.h>
#include <string.h>
 
int main() 
{
    char input[1000][100];  // Assuming maximum 1000 lines, each of maximum length 100
    int i = 0, j = 0;
    int c;
 
    printf("Enter the strings: \n");
 
    // Loop until EOF (Ctrl + D) is encountered
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            input[i][j] = '\0';  // Null-terminate the current line
            i++;  // Move to the next line
            j = 0;  // Reset the column index
        } else {
            input[i][j] = c;
            j++;  // Move to the next character in the current line
        }
    }
 
    printf("\nStrings stored in multidimensional array:\n");
    for (int k = 0; k < i; k++) {
        int len = strlen(input[k]);
        if (len > 50)
            printf("%s\n", input[k]);
    }
    return 0;
}

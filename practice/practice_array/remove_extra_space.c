#include <stdio.h>
#include <ctype.h>
#include <string.h>

void deblank(char string[]) {
    int i, j;
    int space = 0;

    for (i = 0, j = 0; string[i] != '\0'; i++) {
        if (!isspace(string[i])) {
            string[j++] = string[i];
            space = 1;
        } else if (space) {
            string[j++] = ' ';
            space = 0;
        }
    }
    string[j] = '\0';
}

int main() {
    char string[100];

    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);
    //string[strcspn(string, "\n")] = '\0'; // Removing trailing newline from fgets input
    
    printf("Before: %s\n", string);
    deblank(string);
    printf("After: %s\n", string);

    return 0;
}


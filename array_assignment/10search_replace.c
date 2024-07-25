#include <stdio.h>
#include <string.h>
 
#define MAX_SIZE 100
 
void replaceChar(char *str, char findChar, char repChar) {
    while (*str != '\0') {
        if (*str == findChar) {
            *str = repChar;
        }
        str++;
    }
}
 
int main() {
    char str[MAX_SIZE];
    char findChar = 'a';
    char repChar = 'k';
 
    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);
 
    // Iterate through the string until we find '\n' character and replace it with '\0'
    for (int i = 0; i < MAX_SIZE; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
 
    replaceChar(str, findChar, repChar);
 
    printf("String after replacement: %s\n", str);
 
    return 0;
}


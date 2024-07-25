#include <stdio.h>
 
void deleteChar(char *str, char ch) {
    char *src = str; 
    char *dst = str;  
 
    while (*src != '\0') {
        if (*src != ch) {
            *dst = *src;
            dst++; 
        }
        src++;  
    }
    *dst = '\0';
}
 
int main() {
    char str[20];
    printf("Enter the string: \n");
    fgets(str, 20, stdin);
    char ch;
    printf("Enter the character to be searched and deleted from the string: \n");
    scanf(" %c", &ch);  
 
    printf("Original string: %s\n", str);
    deleteChar(str, ch);
    printf("String after deleting '%c': %s\n", ch, str);
 
    return 0;
}

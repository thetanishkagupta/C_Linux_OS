#include <stdio.h>
#include <ctype.h>
 
void remove_except_alpha(char *str);
 
int main() {
    char str[20];
    printf("Enter the string: \n");
    fgets(str, 20, stdin);
    printf("Original string: %s\n", str);
    remove_except_alpha(str);
    printf("String after removing non-alphabetic characters: %s\n", str);
 
    return 0;
}
 
void remove_except_alpha(char *str) {
    char *src = str;  // Pointer to source (original string)
    char *dst = str;  // Pointer to destination (modified string)
    int i = 0;
 
    while (*(src + i) != '\0') {
        if (isalpha(*(src + i))) {
            *dst = *(src + i);
            dst++;
        }
        i++;
    }
 
    *dst = '\0';  // Null-terminate the modified string
}

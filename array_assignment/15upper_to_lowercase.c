#include <stdio.h>

void convertToLower(char *str) {
    while (*str != '\0') {
        if (*str >= 'A' && *str <= 'Z') {
            *str += 'a' - 'A'; // Convert uppercase to lowercase by adding the difference
        }
        str++;
    }
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    printf("String before conversion: %s", str);
    
    convertToLower(str);
    
    printf("String after conversion: %s", str);

    return 0;
}


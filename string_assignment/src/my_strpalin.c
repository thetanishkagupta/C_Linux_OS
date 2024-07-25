#include"../include/hdr.h"

int my_strpalin(char *str) {
    int length = my_strlen(str);
    int i = 0;
    int j = length - 1;

    while (i < j) {
        if (str[i] != str[j]) {
            return 0; // Not a palindrome
        }
        i++;
        j--;
    }
    return 1; // Palindrome
}

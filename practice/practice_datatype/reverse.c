#include <stdio.h>
int reverse(int num) {
    int reversed = 0;
    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return reversed;
}
int main() {
    int num, result;
    printf("Enter a number: ");
    scanf("%d", &num);
    result = reverse(num);
    printf("Reverse of %d is %d\n", num, result);
    return 0;
}


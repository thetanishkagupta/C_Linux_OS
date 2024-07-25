#include <stdio.h>

int countBits(int *num);

int main() {
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    int count = countBits(&num);

    printf("Number of 1-bits in the integer: %d\n", count);

    return 0;
}
int countBits(int *num) {
    int count = 0;
    while (*num != 0) {
        count += (*num) & 1; // Check if the least significant bit is 1
        *num >>= 1; // Right shift the number to check the next bit
    }
    return count;
}


#include <stdio.h>
unsigned int count_set_bits(unsigned int num) {
    unsigned int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count == 1;
}
int main() {
    unsigned int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (count_set_bits(num)) {
        printf("%d is a power of two.\n", num);
    } else {
        printf("%d is not a power of two.\n", num);
    }
    return 0;
}


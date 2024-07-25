#include "../include/hdr.h"
int main() {
    unsigned int num, n;

    printf("Enter a number: ");
    scanf("%u", &num);

    printf("Enter the number of positions to rotate: ");
    scanf("%u", &n);

    unsigned int left_rotated = left_rotate_bits(num, n);
    unsigned int right_rotated = right_rotate_bits(num, n);

    printf("Left rotated: %u\n", left_rotated);
    printf("Right rotated: %u\n", right_rotated);

    return 0;
}

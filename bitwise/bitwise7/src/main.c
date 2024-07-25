#include "../include/hdr.h"
unsigned int count_set_bits(unsigned int);
unsigned int count_clear_bits(unsigned int);

int main() {
    unsigned int num;

    printf("Enter a number: ");
    scanf("%u", &num);

    printf("Number of set bits: %u\n", count_set_bits(num));
    printf("Number of clear bits: %u\n", count_clear_bits(num));

    return 0;
}

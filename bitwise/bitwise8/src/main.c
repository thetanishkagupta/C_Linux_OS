#include "../include/hdr.h"
unsigned int count_leading_set_bits(unsigned int);
unsigned int count_leading_clear_bits(unsigned int);
unsigned int count_trailing_set_bits(unsigned int);
unsigned int count_trailing_clear_bits(unsigned int);
int main() {
    unsigned int num;

    printf("Enter a number: ");
    scanf("%u", &num);

    printf("Number of leading set bits: %u\n", count_leading_set_bits(num));
    printf("Number of leading clear bits: %u\n", count_leading_clear_bits(num));
    printf("Number of trailing set bits: %u\n", count_trailing_set_bits(num));
    printf("Number of trailing clear bits: %u\n", count_trailing_clear_bits(num));

    return 0;
}

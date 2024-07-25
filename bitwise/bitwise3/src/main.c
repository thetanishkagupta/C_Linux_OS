#include "../include/hdr.h"

unsigned int copy_bits(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
int main() {
    unsigned int snum, dnum, n, s, d;

    printf("Enter the source number: ");
    scanf("%u", &snum);

    printf("Enter the destination number: ");
    scanf("%u", &dnum);

    printf("Enter the number of bits to copy: ");
    scanf("%u", &n);

    printf("Enter the source position: ");
    scanf("%u", &s);

    printf("Enter the destination position: ");
    scanf("%u", &d);

    unsigned int result = copy_bits(snum, dnum, n, s, d);
    printf("Updated dnum after copying %u bits from snum to dnum: %u\n", n, result);

    return 0;
}


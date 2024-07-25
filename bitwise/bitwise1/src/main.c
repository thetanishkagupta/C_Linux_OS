#include "../include/hdr.h"
unsigned int swap_bits_within(unsigned int, unsigned int, unsigned int);
int main() {
    unsigned int num;
    unsigned int s, d;

    printf("Enter a number: ");
    scanf("%u", &num);

    printf("Enter the source: ");
    scanf("%u", &s);
    printf("Enter the destination: ");
    scanf("%u", &d);
    
    printf("Bits swapped at positions %u and %u: %u\n", s, d, swap_bits_within(num, s, d));

    return 0;
}

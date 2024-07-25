#include "../include/hdr.h"
int swap_bits_between(unsigned int *, unsigned int *, unsigned int, unsigned int);
int main() {
    unsigned int snum, dnum, s, d;

    printf("Enter the source number: ");
    scanf("%u", &snum);

    printf("Enter the destination number: ");
    scanf("%u", &dnum);

    printf("Enter the source position: ");
    scanf("%u", &s);
    
    printf("Enter the destination position: ");
    scanf("%u", &d);

    if (swap_bits_between(&snum, &dnum, s, d) == 0) {
        printf("Bits swapped between positions %u and %u:\n", s, d);
        printf("Updated snum: %u\n", snum);
        printf("Updated dnum: %u\n", dnum);
    } else {
        printf("Error occurred while swapping bits.\n");
    }
    return 0;
}


#include "../include/hdr.h"
unsigned int toggle_even_bits(unsigned int);
unsigned int toggle_odd_bits(unsigned int);
int main() {
    unsigned int num;

    printf("Enter a number: ");
    scanf("%u", &num);

    printf("After toggling even bits: %u\n", toggle_even_bits(num));
    printf("After toggling odd bits: %u\n", toggle_odd_bits(num));

    return 0;
}

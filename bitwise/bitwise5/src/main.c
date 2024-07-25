#include "../include/hdr.h"
int main() {
    unsigned int num;
    int position;

    printf("Enter a number: ");
    scanf("%u", &num);

    printf("Enter the position of the bit to set: ");
    scanf("%d", &position);

    // Testing and setting bit at the specified position
    test_set_bit(num, position);

    printf("After setting bit at position %d: %u\n", position, num);

    return 0;
}


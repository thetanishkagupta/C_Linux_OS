#include "../include/hdr.h"

int main() {
    unsigned int choice;
    unsigned int num, s, d, snum, dnum, n, position;

    printf("Choose an operation:\n");
    printf("1. Swap bits within a number\n");
    printf("2. Swap bits between two numbers\n");
    printf("3. Copy bits from one number to another\n");
    printf("4. Toggle even bits\n");
    printf("5. Toggle odd bits\n");
    printf("6. Set a bit at a specific position\n");
    printf("7. Left rotate bits\n");
    printf("8. Right rotate bits\n");
    printf("9. Count set bits\n");
    printf("10. Count clear bits\n");
    scanf("%u", &choice);

    switch (choice) {
        case 1:
            printf("Enter a number: ");
            scanf("%u", &num);
            printf("Enter the source: ");
            scanf("%u", &s);
            printf("Enter the destination: ");
            scanf("%u", &d);
            printf("Bits swapped at positions %u and %u: %u\n", s, d, swap_bits_within(num, s, d));
            break;
        case 2:
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
            break;
        case 3:
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
            break;
        case 4:
            printf("Enter a number: ");
            scanf("%u", &num);
            printf("After toggling even bits: %u\n", toggle_even_bits(num));
            break;
        case 5:
            printf("Enter a number: ");
            scanf("%u", &num);
            printf("After toggling odd bits: %u\n", toggle_odd_bits(num));
            break;    
        case 6:
            printf("Enter a number: ");
            scanf("%u", &num);
            printf("Enter the position of the bit to set: ");
            scanf("%d", &position);
            test_set_bit(num, position);
            printf("After setting bit at position %d: %u\n", position, num);
            break;
        case 7:
            printf("Enter a number: ");
            scanf("%u", &num);
            printf("Enter the number of positions to rotate: ");
            scanf("%u", &n);
            printf("Left rotated: %u\n", left_rotate_bits(num, n));
            break;
        case 8:
            printf("Enter a number: ");
            scanf("%u", &num);
            printf("Enter the number of positions to rotate: ");
            scanf("%u", &n);
            printf("Right rotated: %u\n", right_rotate_bits(num, n));
            break;    
        case 9:
            printf("Enter a number: ");
            scanf("%u", &num);
            printf("Number of set bits: %u\n", count_set_bits(num));
            break;
        case 10:
            printf("Enter a number: ");
            scanf("%u", &num);
            printf("Number of clear bits: %u\n", count_clear_bits(num));
            break;    
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}

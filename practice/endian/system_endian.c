#include <stdio.h>

int main() {
    unsigned int num = 1;
    char *byte = (char *)&num;

    if (*byte) {
        printf("Your machine is Little Endian.\n");
    } else {
        printf("Your machine is Big Endian.\n");
    }

    return 0;
}


// linux command to check this on our system : lscpu | grep "Byte Order"

#include <stdio.h>
#include <stdlib.h>

// Function to calculate the sum of command-line arguments
int sum(int argc, char *argv[]) {
    int total = 0;
    for (int i = 1; i < argc; i++) {
        total += atoi(argv[i]); // Convert string argument to integer and add to total
    }
    return total;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <num1> <num2> ... <numN>\n", argv[0]);
        return 1; // Exit with error if no arguments are provided
    }

    int total = sum(argc, argv);
    printf("Sum: %d\n", total);

    return 0;
}


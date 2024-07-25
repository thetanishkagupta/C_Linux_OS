#include <stdio.h>
#include <stdbool.h>
 
#define MAX_SIZE 100
 
int hasDuplicate(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(arr + i) == *(arr + j)) {
                return 1;  // Duplicate found
            }
        }
    }
    return 0;  // No duplicates found
}
 
int main() {
    int arr[MAX_SIZE];
    int size;
 
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
 
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid size entered.\n");
        return 1;
    }
 
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
 
    if (hasDuplicate(arr, size)) {
        printf("Array contains duplicate elements.\n");
    } else {
        printf("Array does not contain duplicate elements.\n");
    }
 
    return 0;
}

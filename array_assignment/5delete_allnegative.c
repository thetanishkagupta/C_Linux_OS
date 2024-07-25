#include <stdio.h>
 
#define MAX_SIZE 100
 
int deleteNegatives(int *arr, int size) {
    int *src = arr;  // Pointer to source (original array)
    int *dst = arr;  // Pointer to destination (updated array)
 
    for (int i = 0; i < size; i++) {
        if (*src >= 0) {
            *dst = *src;
            dst++;
        }
        src++;
    }
 
    return dst - arr;  // Return the new size of the array
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
 
    int newSize = deleteNegatives(arr, size);
 
    printf("Array after deleting negative numbers:\n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
 
    return 0;
}

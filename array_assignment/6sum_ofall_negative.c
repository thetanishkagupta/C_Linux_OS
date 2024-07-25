#include <stdio.h>
 
int addNegativeNumbers(int *arr, int n) {
    int sum = 0;
    int *ptr = arr;  // Pointer to the beginning of the array
 
    for (int i = 0; i < n; i++) {
        if (*ptr < 0){
            sum += *ptr;
        }
        ptr++;  // Move the pointer to the next element
    }
 
    return sum;
}
 
int main() {
    int n;
    printf("Enter the size of an array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of an array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
 
    int sum = addNegativeNumbers(arr, n);
 
    printf("Sum of even numbers: %d\n", sum);
 
    return 0;
}

#include <stdio.h>
 
void deleteElement(int *arr, int n, int pos);

int main() {
    int n,pos;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the position of the element to delete: \n");
    scanf("%d", &pos);

    deleteElement(arr, n, pos-1);

    return 0;
}

void deleteElement(int *arr, int n, int pos) {
    int newArray[n - 1];
    int *dst = newArray;

    int i = 0;
    while (i < n) {
        if (i == pos) {
            // Skip the element at the given position
            i++;
            continue;
        }
        *dst = arr[i];
        dst++;
        i++;
    }

    printf("New array after deletion: \n");
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", newArray[i]);
    }
}


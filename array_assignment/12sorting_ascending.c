#include <stdio.h>
void displayArray(int *arr, int n);
void bubbleSort(int *arr, int n);
 
int main() {
    int n;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elemets of an array: \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Array before Sorting is: \n");
    displayArray(arr, n);
    bubbleSort(arr, n);
    printf("Array after Sorting is: \n");
    displayArray(arr, n);
 
    return 0;
}
 
void bubbleSort(int *arr, int n)
{
    int i,j;
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(*(arr + j) > *(arr + j + 1)){
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}
 
void displayArray(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

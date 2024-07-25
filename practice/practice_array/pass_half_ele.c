#include<stdio.h>
#define MAX 10

int pass(int *arr, int size); 

int main()
{
    int arr[MAX] = {1,2,3,4,5,6,7,8,9,10};
    pass(&arr[5], 5);
    return 0;
}

int pass(int *arr, int size)
{
    for(int i = 0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}


    
    

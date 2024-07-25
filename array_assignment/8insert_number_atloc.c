#include<stdio.h>
#define MAX 100

int insert(int *arr, int n, int pos, int num);

int main()
{
    int arr[MAX];
    int n;
    int pos; int num;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    for(int i =0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("Enter the position: ");
    scanf("%d", &pos);

    printf("Enter the number to be entered : ");
    scanf("%d", &num);
    insert(arr, n, pos-1, num);
    return 0;
}

int insert(int *arr,int n, int pos, int num)
{
    int newArray[n+1];
    int *dst = newArray;
    int i = 0;

    while(i<=n)
    {
        if (i < pos)
        {
            *(dst+i) = *(arr+i);
        }
        else if (i == pos)
        {
            *(dst+i) = num;
            *(dst+i+1) = *(arr+i);
        }
        else 
        {
            *(dst+i+1) = *(arr+i);
        }
        i++;
    }
    printf("The updated array is :");
    for(int i=0; i<n+1; i++)
        printf("%d ", newArray[i]);
    
}





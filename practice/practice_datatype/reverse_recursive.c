#include<stdio.h>
int recursive(int num, int reverse)
{
    int last;
    if(num==0)
    {
        return reverse;
    }
    last = num%10;
    reverse = reverse*10+last;
    num = num/10;
    return recursive(num,reverse);
 }
 int main()
 {
    int reverse,num;
    printf("enter the number\n");
    scanf("%d",&num);
    reverse = recursive(num,reverse);
    printf("reverse of num is:%d\t\n",reverse);
}
 
 

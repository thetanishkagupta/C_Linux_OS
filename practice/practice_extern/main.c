#include<stdio.h>                                                                                                    
  
void addition(int a, int b);
void subtraction(int a, int b);
  
int main() {
    int choice, num1, num2;
  
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("Choose operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");

    printf("Enter choice (1-4): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            addition(num1, num2);
            break;
        case 2:
            subtraction(num1, num2);
            break;

        default:
            printf("Invalid choice\n");
     }
}


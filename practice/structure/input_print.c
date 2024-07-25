#include <stdio.h>

struct Employee {
    int id;
    char name[100];
    float salary;
};

void input_print(struct Employee *emp)
{
    printf("Enter Employee ID: ");
    scanf("%d", &emp -> id);
    getchar();

    printf("Enter Employee Name: ");
    scanf("%[^\n]", emp -> name);

    //scanf("\n");
    printf("Enter the Employee Salary: ");
    scanf("%f", &emp -> salary);

    printf("\nEmployee Details:\n");

    printf("Employee ID: %d\n", emp -> id);
    printf("Empoyee Name: %s\n", emp -> name);    
    printf("Employee salary: %f\n", emp -> salary);
}

int main()
{
    struct Employee emp;

    input_print(&emp);
    
    return 0;
}




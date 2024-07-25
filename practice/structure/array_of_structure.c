#include <stdio.h>

typedef struct {
    int id;
    char name[100];
    float salary;
}Employee;

void input_print(Employee *emp, int count)
{
    for(int i = 0; i<count ;i++)
    {
    printf("Employee ID: %d\n", emp -> id);
    printf("Empoyee Name: %s\n", emp -> name);    
    printf("Employee salary: %f\n", emp -> salary);
    emp++;
    }
}

int main()
{
    int count;
    printf("Enter the number of employee : ");
    scanf("%d", &count);
    Employee emp[count];
    int index;
    for(int i=0; i < count ;i++)
    {
    printf("Enter Employee ID: ");
    scanf("%d", &emp[i].id);
    //getchar();

    printf("Enter Employee Name: ");
    scanf("%s", emp[i].name);

    printf("Enter the Employee Salary: ");
    scanf("%f", &emp[i].salary);
    }
    printf("Enter the index: ");
    scanf("%d", &index);

    //printf("\nEmployee Details:\n");

    input_print(emp+(index-1), count-(index-1));
    
    return 0;
}




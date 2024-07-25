#include <stdio.h>
#include <fcntl.h>

typedef struct{
    int id;
    char name[20];
    double contact;
}employee;

int main(void)
{
    int count;
    FILE *fd;
    printf("enter the number of employees:");
    scanf("%d", &count);
    employee emp[count];

    fd = fopen("db.txt", "w+");
    if(fd == NULL)
    {
       perror("error in opening the file");
    }

    for(int i = 0; i < count; i++)
    {
        printf("Enter the employees detail %d:", i+1);
        scanf("%d", &emp[i].id);
        scanf("%s", emp[i].name);
        scanf("%lf", &emp[i].contact);
        if(fd != NULL)
        {
            fprintf(fd, "%d\t", emp[i].id);
            fprintf(fd, "%s\t", emp[i].name);
            fprintf(fd, "%.0lf\n", emp[i].contact);
        }
    }
    fclose(fd);
}

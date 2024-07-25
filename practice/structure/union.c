#include <stdio.h>
 
union str {
    int m1;
    char m2;
    float m3;
};
 
 
int main(){
 
    union str var;
 
    //var.m1 = 15;
    var.m2 = 'c';
    var.m3 = 2.00;
 
  //  printf("The value of member m1 is %d\n", var.m1);
    printf("The value of member m2 is %c\n", var.m2);
    printf("The valud of member m3 is %f\n", var.m3);
    printf("The size of union is %ld\n", sizeof(var));
 
    return 0;
}

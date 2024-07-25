#include <stdio.h> 
int x; 

void autoStorageClass() 
{ 
	auto int a = 32; 

	printf("Value of the variable 'a' declared as auto: %d\n", a); 

} 

void registerStorageClass() 
{ 
	register char b = 'G'; 

	printf("Value of the variable 'b' declared as register: %d\n", b); 
} 

void externStorageClass() 
{ 
	extern int x; 
	printf("Value of the variable 'x' declared as extern: %d\n", x); 

	x = 2; 
	printf("Modified value of the variable 'x' declared as extern: %d\n", x); 
} 

void staticStorageClass() 
{ 
	int i = 0; 

	for (i = 1; i < 5; i++) { 
		static int y = 5; 

		int p = 10; 

		y++; 
		p++; 

		printf("\nThe value of 'y'declared as static in %d iteration is %d\n", i, y); 

		printf("The value of non-static variable 'p' in %d iteration is %d\n", i, p); 
	} 
} 

int main() 
{ 
	autoStorageClass(); 
	registerStorageClass(); 
	externStorageClass(); 
	staticStorageClass(); 
	return 0; 
} 


/* Compilar: gcc -g pointer3.c -o pointer3C       */                                                         

#include <stdio.h>

#define MAXIMO 10

int main(void){
	
	int a[MAXIMO];
 	
	int *a_ptr = NULL; 
	
	int i;

	for(i = 0; i < MAXIMO; i++)
	{			
		a[i] = i;
	}
			
	a_ptr = a;

	for(i = 0; i < MAXIMO; i++)
	{			
		printf("%4d %4d\n", a[i], *a_ptr);
		a_ptr ++;
	}

	return 0;
}

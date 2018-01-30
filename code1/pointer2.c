
/* Compilar: gcc -g pointer2.c -o pointer2C       */                                                         


#include <stdio.h>

#define MAXIMO 10

int main(void){
	
	int    a[MAXIMO];
 	double b[MAXIMO]; 
 	
	int    *a_ptr = NULL; 
 	double *b_ptr = NULL;
 	
 	a_ptr = a;
 	b_ptr = b;
	
	int i;

	for(i = 0; i < MAXIMO; i++)
	{			
		a[i] = i;
		b[i] = i + 0.5;
	}

	for(i = 0; i < MAXIMO; i++)
	{			
		printf("%4d %4d\n", a[i]    , *(a_ptr + i));
		printf("%4d %4d\n", a_ptr[i], *(a + i)    );
	}

	return 0;
}


/* Compiling: gcc -g pointer5.c -o pointer5C       */                                                         


#include <stdio.h>
#include <stdlib.h>

#define MAXIMO 10

int main(void){
 		
	int a[MAXIMO];
	
	int *a_ptr = NULL; 
	a_ptr = (int*) malloc (MAXIMO * sizeof(int));

	int i;

	for(i = 0; i < MAXIMO; i++)
	{			
		a[i] = i;
		a_ptr[i] = i;
		printf("%4d %4d\n", a[i], a_ptr[i]);
	}
			
	free (a_ptr);	
	a_ptr = NULL;
}

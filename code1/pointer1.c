
/* Compilar: gcc -g pointer1.c -o pointer1C       */                                                         

#include <stdio.h>

int main(void){
	
 	int    a;
 	double b; 
 
 	int    *a_ptr = NULL; 
 	double *b_ptr = NULL;
 		
 	a = 5;
	b = 12.6; 
	
	a_ptr = &a; 
	b_ptr = &b; 
	
	printf("%4d %16p\n",    a,  a_ptr); 
	printf("%4.1lf %16p\n", b,  b_ptr); 
	printf("%4d %16d\n",    a, *a_ptr); 

	return 0;
}


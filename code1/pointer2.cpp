
/* Compilar: g++ -g pointer2.cpp -o pointer2CPP   */                                                         

#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

#define MAXIMO 10

int main(void){
	
	int    a[MAXIMO];
 	double b[MAXIMO]; 
 	
	int    *a_ptr = NULL; 
 	double *b_ptr = NULL;
 	
 	a_ptr = a;
 	b_ptr = b;
	
	for(int i = 0; i < MAXIMO; i++)
	{			
		a[i] = i;
		b[i] = i + 0.5;
	}

	for(int i = 0; i < MAXIMO; i++)
	{	
		cout << setw(4) << a[i] << setw(4) << *(a_ptr + i) << endl; 
		cout << setw(4) << a_ptr[i] << setw(4) << *(a + i) << endl; 
	}

	return 0;
}

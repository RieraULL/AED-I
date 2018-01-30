
/* Compiling: gcc -g pointer5.cpp -o pointer5CPP   */                                                         


#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

#define MAXIMO 10

int main(void){
 		
	int a[MAXIMO];
	
	int *a_ptr = NULL; 
	int *b_ptr = NULL;

	a_ptr = new int [MAXIMO];
	b_ptr = new int;

	*b_ptr = 5;

	for(int i = 0; i < MAXIMO; i++)
	{			
		a[i] = i;
		a_ptr[i] = i;
		cout << setw(4) << a[i] << setw(4) << a_ptr[i] << endl;
	}

	cout << setw(4) << *b_ptr << endl;
			
	delete [] a_ptr;	
	a_ptr = NULL;

	delete b_ptr;
   	b_ptr = NULL;
}

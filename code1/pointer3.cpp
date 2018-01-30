
/* Compilar: g++ -g pointer3.cpp -o pointer3CPP   */                                                         

#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

#define MAXIMO 10

int main(void){
	
	int a[MAXIMO];
 	
	int *a_ptr = NULL; 

	for(int i = 0; i < MAXIMO; i++)
	{			
		a[i] = i;
	}
			
	a_ptr = a;

	for(int i = 0; i < MAXIMO; i++)
	{			
		cout << setw(4) << a[i] << setw(4) << *a_ptr << endl;
		a_ptr ++;
	}

	return 0;
}

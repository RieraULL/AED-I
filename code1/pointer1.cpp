
/* Compilar: g++ -g pointer1.cpp -o pointer1CPP   */                                                         

#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

int main(void){
	
 	int    a;
 	double b; 
 
 	int    *a_ptr = NULL; 
 	double *b_ptr = NULL;
 		
 	a = 5;
	b = 12.6; 
	
	a_ptr = &a; 
	b_ptr = &b; 
	
	cout << setw(4) << a << setw(16) <<  a_ptr << endl; 
	cout << setw(4) << fixed << setprecision(1) << b << setw(16) <<  b_ptr << endl; 
	cout << setw(4) << a << setw(16) << *a_ptr << endl; 

	return 0;
}

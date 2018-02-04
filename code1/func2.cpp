#include <iostream>

#define N_OP 4

using namespace std;
 
typedef int (*opera_ptr)(int, int);
 
int suma (int n1, int n2) { return n1 + n2; }
int rest (int n1, int n2) { return n1 - n2; }
int mult (int n1, int n2) { return n1 * n2; }
int div  (int n1, int n2) { return n1 / n2; }
 

int opera(int n1, int n2, opera_ptr operador) 
{
   return (*operador)(n1, n2);
}
 
int main(void) 
{
   opera_ptr opera_array[] = {suma, rest, mult, div};

   const int a = 10, b = 5;

   for(size_t i = 0; i < N_OP; i++)
		cout << opera(a, b, opera_array[i]) << endl;
}

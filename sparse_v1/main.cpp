#include "vector_t.hpp"
#include "sparse_vector_t.hpp"

#include <iostream>
using namespace std;

#define V_SZ 10000
#define EPS  1E-3

int main(void)
{
	vector_t v(V_SZ);

	for(int i = 0; i < V_SZ; i++)
		v.get_set_v(i) = 0.0;

	v.get_set_v(0)    = 1.0; 
	v.get_set_v(1000) = 1.0; 
	v.get_set_v(2000) = 1.0; 
	v.get_set_v(3000) = 1.0; 
	v.get_set_v(4000) = 1.0; 
	v.get_set_v(5000) = 1.0;

	sparse_vector_t sv(v, EPS);	

	sv.write(cout);
	cout << endl;
}

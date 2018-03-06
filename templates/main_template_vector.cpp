#include <cstdio>
#include <iostream>

#include "template_vector_t.hpp"

using namespace std;

int main(void)
{


  	vector_t<double> v(10);

	for(int i = 0; i < v.get_sz(); i++)
		v.get_set_v(i) = 34.3346 + i * 0.5;

	v.write(cout);
	cout << endl;

  	vector_t<int> w(10);

	for(int i = 0; i < v.get_sz(); i++)
		w.get_set_v(i) = i;

	w.write(cout);
	cout << endl;	

	return 0;
}

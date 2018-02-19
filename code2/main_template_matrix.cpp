#include <cstdio>
#include <iostream>

#include "template_matrix_t.hpp"

using namespace std;

int main(void)
{


  	matrix_t<double> A(10,10);

	for(int i = 1; i <= A.get_m(); i++)
		for(int j = 1; j <= A.get_n(); j++)
			A.get_set(i,j) = 1.233 + i * 0.3;

	A.write(cout);
	cout << endl;

  	matrix_t<int> B(10,10);

	for(int i = 1; i <= B.get_m(); i++)
		for(int j = 1; j <= B.get_n(); j++)
			B.get_set(i,j) = i * B.get_n() + j;

	B.write(cout);
	cout << endl;

  	matrix_t<char> C(10,10);

	for(int i = 1; i <= C.get_m(); i++)
		for(int j = 1; j <= C.get_n(); j++)
			C.get_set(i,j) = 'A' + i + j;

	C.write(cout);
	cout << endl;

}


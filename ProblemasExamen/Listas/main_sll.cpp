#include <iostream>

#include "sll_t.hpp"

#define N_CHARS 26

using namespace std;

int main(void)
{
	AED::sll_t<char> lista;

	for(int i = 0; i < N_CHARS; i++)
		lista.insert_head( new AED::sll_node_t<char>('a' + i) );

	lista.write(cout);
	cout << endl;

	lista.writeReverse(cout);
	cout << endl;
	
	lista.writeDirect(cout);
	cout << endl;	
	
	lista.writeReverseStack(cout);
	cout << endl;	

	return 0;
}

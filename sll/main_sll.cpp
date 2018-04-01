#include <iostream>

#include "sll_t.hpp"
#include "lista_char_t.hpp"

#define N_CHARS 26

using namespace std;

int main(void)
{
	AED::sll_t<char> lista;

	for(int i = 0; i < N_CHARS; i++)
		lista.insert_head( new AED::sll_node_t<char>('a' + i) );

	lista.write(cout);
	cout << endl;

	AED::sll_node_t<char>* nodo = lista.extract_head();
	char dato = nodo->get_data();
	delete nodo;

	cout << "Dato 1: " << dato << endl;

	nodo = lista.extract_head();
	dato = nodo->get_data();
	delete nodo;

	cout << "Dato 2: " << dato << endl;

	nodo = lista.extract_head();
	dato = nodo->get_data();
	delete nodo;

	cout << "Dato 3: " << dato << endl;

	lista.write(cout);
	cout << endl;

	nodo = lista.extract_after(lista.head());
	dato = nodo->get_data();
	delete nodo;

	cout << "Dato 4: " << dato << endl;

	nodo = lista.extract_after(lista.head()->get_next());
	dato = nodo->get_data();
	delete nodo;

	cout << "Dato 5: " << dato << endl;

	lista.write(cout);
	cout << endl;

	nodo = lista.head();
	dato = nodo->get_data();

	cout << "Dato 6: " << dato << endl;

	lista.write(cout);
	cout << endl;
      
      lista_char_t lista_char;
      
	for(int i = 0; i < N_CHARS; i++)
		lista_char.insert_head('a' + i); 

      lista_char.write(cout);
      cout << endl;

      while(!lista_char.empty()){
            
            cout << lista_char.extract_head() << endl;
            
            lista_char.write(cout);
            cout << endl;
      }

	return 0;
}

#include <iostream>

#include "sll_t.hpp"
#include "lista_char_t.hpp"

#define N_CHARS 26

using namespace std;

int main(void)
{
 /*     {
	AED::sll_t<char> L1;
      AED::sll_t<char> L2;

	for(int i = 14; i >= 0; i-=2)
		L1.insert_head( new AED::sll_node_t<char>('a' + i) );
            
	for(int i = 25; i >= 0; i-=2)
		L2.insert_head( new AED::sll_node_t<char>('a' + i) );

      AED::sll_t<char> L;
      
      L1.write(cout); cout << endl;
      L2.write(cout); cout << endl;
      L.write(cout);  cout << endl;
      
      cout << endl;
      
      L.merge1(L1, L2);

      L1.write(cout); cout << endl;
      L2.write(cout); cout << endl;
      L.write(cout);  cout << endl;
	cout << endl;
      }
 */     
 /*     {
	AED::sll_t<char> L1;
      AED::sll_t<char> L2;

	for(int i = 0; i <=14; i+=2)
		L1.insert_head( new AED::sll_node_t<char>('a' + i) );
            
	for(int i = 1; i <= 25; i+=2)
		L2.insert_head( new AED::sll_node_t<char>('a' + i) );

      AED::sll_t<char> L;
      
      L1.write(cout); cout << endl;
      L2.write(cout); cout << endl;
      L.write(cout);  cout << endl;
      
      cout << endl;
      
      L.merge2(L1, L2);

      L1.write(cout); cout << endl;
      L2.write(cout); cout << endl;
      L.write(cout);  cout << endl;
	cout << endl;
      }   
*/      
      {
	AED::sll_t<char> L1;
            
	for(int i = 25; i >= 0; i--)
		L1.insert_head( new AED::sll_node_t<char>('a' + i) );

      AED::sll_t<char> L;
      
      L1.write(cout); cout << endl;
      L.write(cout);  cout << endl;
      
      cout << endl;
      
      L.invPar(L1);

      L1.write(cout); cout << endl;
      L.write(cout);  cout << endl;
	cout << endl;
      }         
   
	return 0;
}

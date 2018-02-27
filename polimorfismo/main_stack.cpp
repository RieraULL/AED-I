#include <iostream>
#include "stack_v_t.hpp"

using namespace std;

int main(void)
{
	
	stack_v_t<char> pila_vector;



	for(int i = 0; i < MAX_STACK_SIZE + 1; i++){

		try {
			pila_vector.push('a' + i);
		 }
		catch(stack_exception_t& e)
  		{
    			cout << "Excepción de la clase 'stack_t': ";
   			cout << e.what() <<  endl;
  		}
 		catch(exception& e)
  		{
		    	cout << e.what() <<  endl;
  		}
	}

	while(!pila_vector.empty()){
		
		try{
			pila_vector.pop();
		}
		catch(stack_exception_t& e)
  		{
    			cout << "Excepción de la clase 'stack_t': ";
   			cout << e.what() <<  endl;
  		}
 		catch(exception& e)
  		{
		    	cout << e.what() <<  endl;
  		}
	}
	

	try{
		pila_vector.pop();
	}
	catch(stack_exception_t& e)
	{
		cout << "Excepción de la clase 'stack_t': ";
		cout << e.what() <<  endl;
	}
	catch(exception& e)
	{
	    	cout << e.what() <<  endl;
	}
	

}

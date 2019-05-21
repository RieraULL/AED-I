#include <cstdio>
#include <stack>
#include <vector>
#include <utility>
#include <cmath>
#include <iostream>

using namespace std;

/*Impleméntese el método int rsearch(int i, int d, const T& x) de la clase vector_t que efectúa la búsqueda lineal recursiva en un vector no ordenado, devolviendo la posición del elemento encontrado y -1 si no lo encuentra.
*/

int rsearch(const int* v, int i, int d, int x)
{
	int c = -1;

	if (i <= d){

		c = (i + d) / 2;

		if (v[c] != x) {

			const int  c1 = rsearch(v, i, c - 1, x);
			const int  c2 = rsearch(v, c + 1, d, x);

			c = max(c1, c2);
		}
	}

	return c;
}

/* Impleméntese el método int bsearch(int i, int d, const T& x) de la clase vector_t que efectúa la búsqueda binaria recursiva en un vector ordenado, devolviendo la posición del elemento encontrado y -1 si no lo encuentra.
*/

int bsearch(const int* v, int i, int d, int x)
{
	int c = -1;

	if (i <= d){

		c = (i + d) / 2;

		if (v[c] != x) {

			if (x < v[c]) c = bsearch(v, i, c - 1, x);
			else           c = bsearch(v, c + 1, d, x);
		}
	}

	return c;
}

/* Impleméntese los métodos void generate_all(void) y void generate(int i), que rellenerá y mostrarán de forma recursiva todos los posibles valores que pueden tomar los dígitos del objeto. */
  
    #define N_DIGITS 4

    void write(const vector<int>& v, ostream& os)
    {
        for(unsigned int i = 0; i < v.size(); i++)
            os << v[i];
            
        os << endl;
    }

	void generate(vector<int>& number, int i)
	{
	    if (i < 0) 
	        write(number, cout);
	    else {
	        
	        for(int b = 0; b < 2; b ++){
	            number[i] = b;
	            generate(number, i - 1);
	        }
	    }
	}

	void generate_all(void)
	{
	    vector<int> number(N_DIGITS);
	    generate(number, N_DIGITS - 1);
	}


/* Impléméntese el método void generate_all2(void), que rellenerá y mostrarán de forma no recursiva todos los posibles valores que pueden tomar los dígitos del objeto. Con este propósito se deberá hacer uso de una pila que almacenará elementos de tipo par_t. Cada objeto de tipo par_t almacena uno de los dos posibles valores que puede tomar un dígito, así como la posición del dígito dentro del vector.
La pila debe inicializarse con dos elementos relativos a los valores 0 y 1, para la posición n_digits() - 1. Mientras la pila no esté vacía, se debe extraer un (b, l) elemento de la pila, situar el valor b en la posición l del vector, y preguntar si l es igual a cero. En caso afirmativo se imprime el número, si no, se introducen dos nuevos pares en la pila (uno con valor 0 y otro 1) correspondiente a la posición l - 1.
*/

    typedef pair<int, int> par_t;

	void generate_all2(void)
	{
	    stack<par_t> Pila;
	    vector<int> number(N_DIGITS);
	    
	    for(int b = 0; b < 2; b++) 
	        Pila.push(par_t(b, N_DIGITS - 1));
	    
	    while(!Pila.empty())
	    {
	        const par_t par = Pila.top();
	        Pila.pop();
	        
	        const int b = par.first;
	        const int l = par.second;
	        
	        number[l] = b;
	        
	        if (l <= 0) 
	            write(number, cout);
	        else {
	            for(int b = 0; b < 2; b++) 
	                Pila.push(par_t(b, l - 1));	            
	        }
	    }
	}
	
	int main(void)
	{
	    const int v[] = {3,5,7,9,3,1,3,4};
	    const int posv = rsearch(v, 0, 7, 3);
	    cout << "Posición: " << posv << endl;
	    
	    const int w[] = {3,5,7,9,11,15,33,45};
	    const int posw = rsearch(w, 0, 7, 3);
	    cout << "Posición: " << posw << endl;	
	    
	    cout << endl;
	    
	    generate_all();
	    cout << endl;
	    generate_all2();
	    cout << endl;
	    
	    return 0;
	}

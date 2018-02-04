# Problemas resuelto

## Problema 1
### Enunciado
Construir una función que devuelva el [producto escalar](https://es.wikipedia.org/wiki/Producto_escalar) de dos vectores. La cabecera de la función debe ser:

~~~cpp
int scal_prod(int v1[], int v2[], size_t sz)
~~~ 

Elabora además, un programa principal en el que se inicialicen dos vectores `v1` y `v2` con números aleatorios con valores comprendidos entre -50 y 50, y efectúe el producto escalar entre ambos. 

### Solución

Ref. [Prob1](prob1/prob1.cpp)

~~~cpp
int scal_prod(int v1[], int v2[], size_t sz)
{
	int aux = 0;

	for(size_t i = 0; i < sz; i ++)
		aux = aux + v1[i] * v2[i];

	return aux;
}


int main(void)
{
	int v1[MAX_SZ], v2[MAX_SZ];

	for(size_t i = 0; i < MAX_SZ; i++){

		v1[i] = rand() % (2 * (MAX_VAL + 1)) - MAX_VAL;
		v2[i] = rand() % (2 * (MAX_VAL + 1)) - MAX_VAL;
	}

	for(size_t i = 0; i < MAX_SZ; i++)
		cout << setw(4) << v1[i];

	cout << endl;


	for(size_t i = 0; i < MAX_SZ; i++)
		cout << setw(4) << v2[i];

	cout << endl;

	const int sp = scal_prod(v1, v2, MAX_SZ);

	cout << endl;
	cout << "  v1 . v2 = " << sp << endl;
}
~~~

## Problema 2

### Enunciado
Diseñar e implementar una función que devuelva el número de ocurrencias de un elemento `val` dentro de un vector de tipo `double`, con una precisión `tol`.
La cabecera del procedimiento debe ser

~~~cpp
size_t count_eq(double v[], int sz, double val, double tol)
~~~

Implémentese, asimismo, un programa principal que inicialice un vector y muestre varios casos con distintas tolerancias.

### Solución

Ref. [Prob2](prob1/prob2.cpp)

~~~cpp
size_t count_eq(double v[], int sz, double val, double tol)
{
	size_t count = 0;

	for(size_t i = 0; i < sz; i ++)
		if (fabs(v[i] - val) < tol)
			count ++;

	return count;
}

int main(void)
{
	double v1[] = {0.9, 0.99, 0.999, 0.9999, 1.0, 1.0001, 1.001, 1.01, 1.1};

	const size_t c1 = count_eq(v1, MAX_SZ, 1.0, 1E-4);
	const size_t c2 = count_eq(v1, MAX_SZ, 1.0, 1E-3);
	const size_t c3 = count_eq(v1, MAX_SZ, 1.0, 1E-2);
	const size_t c4 = count_eq(v1, MAX_SZ, 1.0, 1E-1);
	
	cout << "Tolerancia 1E-4: " << setw(2) << c1 << endl;
	cout << "Tolerancia 1E-3: " << setw(2) << c2 << endl;
	cout << "Tolerancia 1E-2: " << setw(2) << c3 << endl;
	cout << "Tolerancia 1E-1: " << setw(2) << c4 << endl;
}
~~~

## Problema 3

### Enunciado

1. Diséñese e impleméntese una función que cuente el número de elementos menores que el valor `val` dentro de un vector `double` con una tolerancial `tol`. 
2. Diséñese e impleméntese una función que cuente el número de elementos mayores que el valor `val` dentro de un vector `double` con una tolerancial `tol`.

La cabecera de los procedimientos debería ser:

~~~cpp
size_t count_less(double v[], int sz, double val, double tol)
size_t count_great(double v[], int sz, double val, double tol)
~~~

### Solución

Ref. [Prob3](prob1/prob3.cpp)

~~~cpp
size_t count_less(double v[], int sz, double val, double tol)
{
	size_t count = 0;

	for(size_t i = 0; i < sz; i ++)
		if ((v[i] - val) < -tol)
			count ++;

	return count;
}

size_t count_great(double v[], int sz, double val, double tol)
{
	size_t count = 0;

	for(size_t i = 0; i < sz; i ++)
		if ((v[i] - val) > tol)
			count ++;

	return count;
}

int main(void)
{
	double v1[] = {0.9, 0.99, 0.999, 0.9999, 1.0, 1.0001, 1.001, 1.01, 1.1};

	const size_t c1 = count_less(v1, MAX_SZ, 1.0, 1E-4);
	const size_t c2 = count_less(v1, MAX_SZ, 1.0, 1E-3);
	const size_t c3 = count_less(v1, MAX_SZ, 1.0, 1E-2);
	const size_t c4 = count_less(v1, MAX_SZ, 1.0, 1E-1);

	const size_t c5 = count_great(v1, MAX_SZ, 1.0, 1E-4);
	const size_t c6 = count_great(v1, MAX_SZ, 1.0, 1E-3);
	const size_t c7 = count_great(v1, MAX_SZ, 1.0, 1E-2);
	const size_t c8 = count_great(v1, MAX_SZ, 1.0, 1E-1);
	
	cout << "LESS  Tolerancia 1E-4: " << setw(2) << c1 << endl;
	cout << "LESS  Tolerancia 1E-3: " << setw(2) << c2 << endl;
	cout << "LESS  Tolerancia 1E-2: " << setw(2) << c3 << endl;
	cout << "LESS  Tolerancia 1E-1: " << setw(2) << c4 << endl;
	cout << endl;
	cout << "GREAT Tolerancia 1E-4: " << setw(2) << c5 << endl;
	cout << "GREAT Tolerancia 1E-3: " << setw(2) << c6 << endl;
	cout << "GREAT Tolerancia 1E-2: " << setw(2) << c7 << endl;
	cout << "GREAT Tolerancia 1E-1: " << setw(2) << c8 << endl;
}
~~~

## Problema 4

### Enunciado

1. Diseñar e implementar una función que sume todos los elementos de un vector `int`.
2. Diseñar e implementar una función de cuente el número de elementos pares que hay dentro de un vector `int`. 
3. Diseñar e implementar una función de cuente el número de elementos impares que hay dentro de un vector `int`. 

Las cabeceras debería ser de la siguiente manera:

~~~cpp
int suma(int v[], size_t sz)
size_t cont_pair(int v[], size_t sz)
size_t cont_odd(int v[], size_t sz)
~~~



### Solución

Ref. [Prob4](prob1/prob4.cpp)

~~~cpp
using namespace std;

int suma(int v[], size_t sz)
{
	int aux = 0;

	for(size_t i = 0; i < sz; i ++)
		aux = aux + v[i];

	return aux;
}

size_t cont_pair(int v[], size_t sz)
{
	size_t cont = 0;

	for(size_t i = 0; i < sz; i ++)
		 if (v[i] % 2 == 0)
			cont ++;

	return cont;
}

size_t cont_odd(int v[], size_t sz)
{
	size_t cont = 0;

	for(size_t i = 0; i < sz; i ++)
		 if (v[i] % 2 != 0)
			cont ++;

	return cont;
}


int main(void)
{
	int v[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


	cout << "Suma   : " << setw(4) << suma(v, MAX_SZ)      << endl;
	cout << "Pares  : " << setw(4) << cont_pair(v, MAX_SZ) << endl;
	cout << "Impares: " << setw(4) << cont_odd(v, MAX_SZ)  << endl;	
}
~~~
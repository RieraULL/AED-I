#include <iostream>
#include <iomanip>
#include <cstdlib>

#define MAX_SZ  10
#define MAX_VAL 50

using namespace std;

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


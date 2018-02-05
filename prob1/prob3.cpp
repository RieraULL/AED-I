#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

#define MAX_SZ  9
#define MAX_VAL 2

using namespace std;

int count_less(double v[], int sz, double val, double tol)
{
	int count = 0;

	for(int i = 0; i < sz; i ++)
		if (v[i] - val < -tol)
			count ++;

	return count;
}

int count_great(double v[], int sz, double val, double tol)
{
	int count = 0;

	for(int i = 0; i < sz; i ++)
		if (v[i] - val > tol)
			count ++;

	return count;
}

int main(void)
{
	double v1[] = {0.9, 0.99, 0.999, 0.9999, 1.0, 1.0001, 1.001, 1.01, 1.1};

	const int c1 = count_less(v1, MAX_SZ, 1.0, 1E-4);
	const int c2 = count_less(v1, MAX_SZ, 1.0, 1E-3);
	const int c3 = count_less(v1, MAX_SZ, 1.0, 1E-2);
	const int c4 = count_less(v1, MAX_SZ, 1.0, 1E-1);

	const int c5 = count_great(v1, MAX_SZ, 1.0, 1E-4);
	const int c6 = count_great(v1, MAX_SZ, 1.0, 1E-3);
	const int c7 = count_great(v1, MAX_SZ, 1.0, 1E-2);
	const int c8 = count_great(v1, MAX_SZ, 1.0, 1E-1);
	
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


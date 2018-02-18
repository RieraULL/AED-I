#include <iostream>

#include "point_t.hpp"
#include "line_eq_t.hpp"

using namespace std;

int main(void)
{
	point_t p1(3, 4);
	point_t p2(4, 3);

	line_equ_t l1(1, - 1);

	cout << "Distancia entre la recta ";  
	l1.write(cout);
	cout << " y el punto ";
	p1.write(cout);
	cout << " es ";
	cout << l1.distance(p1) << endl;

	cout << "Distancia entre la recta ";  
	l1.write(cout);
	cout << " y el punto ";
	p2.write(cout);
	cout << " es ";
	cout << l1.distance(p2) << endl;

	return 0;
}

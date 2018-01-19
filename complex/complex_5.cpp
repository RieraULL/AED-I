
#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;

/* --------------------------------------- 
   Declaración del tipo complejo
   ---------------------------------------*/

class complex_t {

	double r_;
	double i_;

public:

	complex_t(double r,double i);
	complex_t(void);

	~complex_t(void);
	
	void imprime_complejo(void);

	void set_real(double r);
	void set_imag(double i);
	
	double get_real(void);
	double get_imag(void);
	double get_modulo(void);
	double get_fase(void);

};
 
complex_t::complex_t(double r,double i)
{
	r_=r;
	i_=i;

}

complex_t::complex_t(void)
{
	r_=0;
	i_=0;

}

complex_t::~complex_t(void)
{
	r_=0;
	i_=0;

}

void complex_t::imprime_complejo(void)
{
	char aux[80];

	sprintf(aux," %3.1lf + %3.1lfi ",r_,i_);
	cout << aux; 
}

void complex_t::set_real(double r)
{
	r_=r;
}

void complex_t::set_imag(double i)
{
	i_=i;
}

double complex_t::get_real(void)
{
	return r_;
}

double complex_t::get_imag(void)
{
	return i_;
}

double complex_t::get_modulo(void)
{
	return sqrt(r_*r_+i_*i_);	
}

double complex_t::get_fase(void)
{
	return atan2(i_,r_);	
}

/* --------------------------------------- 
   Funciones que implican más de un complejo
   ---------------------------------------*/

complex_t operator+(complex_t& c1,complex_t& c2)   // <==== OJO!!! sobrecargando operador
{
	complex_t aux;

	aux.set_real(c1.get_real()+c2.get_real());
	aux.set_imag(c1.get_imag()+c2.get_imag());

	return aux;
}

complex_t operator*(complex_t& c1,complex_t& c2)   // <==== OJO!!! sobrecargando operador
{
	complex_t aux;

	aux.set_real(c1.get_real()*c2.get_real()- c1.get_imag()*c2.get_imag());
	aux.set_imag(c1.get_real()*c2.get_imag()+ c2.get_real()*c1.get_imag());

	return aux;	
}


bool operator==(complex_t& c1,complex_t& c2)     // <==== OJO!!! sobrecargando operador
{
	return (c1.get_real()==c2.get_real())&&(c1.get_imag()==c2.get_imag());
}


/* --------------------------------------- 
   Programa principal
   ---------------------------------------*/

int main(void)
{
	// Declaración de cuatro variables de tipo complejo
	complex_t a(1,2),b(2,3),c(3,4),d;

	// Muestra los número complejos

	cout << endl;
	a.imprime_complejo();
	cout << endl;
	b.imprime_complejo();
	cout << endl;
	c.imprime_complejo();
	cout << endl;
	d.imprime_complejo();
	cout << endl;
	cout << endl;

	// Muestra la variable a			
	cout << "Parte real      : "<< a.get_real()<< std::endl;
	cout << "Parte imaginaria: "<< a.get_imag()<< std::endl;
	cout << "Módulo          : "<< a.get_modulo()<< std::endl;
	cout << "Fase            : "<< a.get_fase()<<std::endl;
	cout << endl;

	// Altera una de las variables
	cout << "Cambiando número: ";a.imprime_complejo(); 
	a.set_real(5);
        //a.r_=5;               // ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!
	cout << " a ";a.imprime_complejo(); cout << endl;
	cout << endl;

	//Suma compleja
	cout << "Suma            : "; a.imprime_complejo(); cout << " + ";b.imprime_complejo(); cout << " = ";

	c = a + b;    // <==== OJO!!! sobrecargando operador

	c.imprime_complejo();
	cout << endl;
	cout << endl;

	//Producto complejo
	cout << "Producto        : "; a.imprime_complejo(); cout << " * ";b.imprime_complejo(); cout << " = ";

	d= a * b;    // <==== OJO!!! sobrecargando operador

	d.imprime_complejo();
	cout << endl;
	cout << endl;

}


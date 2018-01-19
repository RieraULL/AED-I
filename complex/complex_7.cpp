
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

	void operator= (double r); 			// <==== OJO!!! sobrecargando operador

	void operator() (double r,double i); 	// <==== OJO!!! sobrecargando operador

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

void complex_t::operator=(double r)   		// <==== OJO!!! sobrecargando operador
{
	r_=r;
}

void complex_t::operator()(double r, double i)   	// <==== OJO!!! sobrecargando operador
{
	r_=r;
	i_=i;
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

complex_t operator+(complex_t& c1,complex_t& c2)   
{
	complex_t aux;

	aux.set_real(c1.get_real()+c2.get_real());
	aux.set_imag(c1.get_imag()+c2.get_imag());

	return aux;
}

complex_t operator*(complex_t& c1,complex_t& c2)   
{
	complex_t aux;

	aux.set_real(c1.get_real()*c2.get_real()- c1.get_imag()*c2.get_imag());
	aux.set_imag(c1.get_real()*c2.get_imag()+ c2.get_real()*c1.get_imag());

	return aux;	
}


bool operator==(complex_t& c1,complex_t& c2)   
{
	return (c1.get_real()==c2.get_real())&&(c1.get_imag()==c2.get_imag());
}


/* --------------------------------------- 
   Programa principal
   ---------------------------------------*/

int main(void)
{
	// Declaración de cuatro punteros a objeto de tipo complejo
	complex_t* a_d = NULL;
	complex_t* b_d = NULL;
	complex_t* c_d = NULL;
	complex_t* d_d = NULL;

	// Creamos objetos dinámicos (Ojo con la sintáxis)
	a_d = new complex_t (1,2);	
	b_d = new complex_t (2,3);
	c_d = new complex_t (3,4);
	d_d = new complex_t;

	// Muestra los número complejos

	cout << endl;
	a_d->imprime_complejo();
	cout << endl;
	b_d->imprime_complejo();
	cout << endl;
	c_d->imprime_complejo();
	cout << endl;
	d_d->imprime_complejo();
	cout << endl;
	cout << endl;


	// Muestra la variable a			
	cout << "Parte real      : "<< a_d->get_real()<< std::endl;
	cout << "Parte imaginaria: "<< a_d->get_imag()<< std::endl;
	cout << "Módulo          : "<< a_d->get_modulo()<< std::endl;
	cout << "Fase            : "<< a_d->get_fase()<<std::endl;
	cout << endl;

	// Nunca olvidar liberar la memoria
	delete a_d;
	delete b_d;
	delete c_d;
	delete d_d;

	// Accediendo incorrectamente a un puntero.
	a_d->imprime_complejo();
	cout << endl;
	cout << endl;

	cout << "La instrucción anterior hace un acceso erróneo a memoria ";
	cout << "porque accede a un área ya liberada."<< endl<<endl;
	cout << "Para evitar errores, asigna NULL al puntero liberado."<< endl;
	cout << "Y si accedes a memoria de forma errónea habrá un error en tiempo de ejecución ";
	cout << "como el que se producirá a continuación:"<< endl<<endl;

	// Para evitar resultados erróneos siempre:
	a_d = NULL;
	b_d = NULL;
	c_d = NULL;
	d_d = NULL;

	// Accediendo desde un puntero nulo. Dará error en tiempo de ejecución.
	a_d->imprime_complejo();
}


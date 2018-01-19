# Programación Orientada a Objetos

Programación Orientada a Objetos (OOP)

## Clases

Una clase es una estructura que permite la descripción de las características (atributos) y comportamiento (métodos) de un conjunto de objetos. Las clases, al igual que muchos otros elementos de la OOP puede implementarse en casi cualquier lenguaje de programación. 

El siguiente fragmento de [código](complex/complex_1.c) en lenguaje C persigue crear un nuevo tipo de dato denominado `complex_t`, que representa un número complejo y algunas de sus operaciones asociadas. El lenguaje C no es orientado a objetos, pero aún así hemos podido implementar esta característica de la OOP.

```c
struct struct_complex_t {
	double r_;
	double i_;
};

typedef struct struct_complex_t complex_t; 

void imprime_complejo(complex_t* c)
{
	printf("%3.1lf + %3.1lfi", c->r_, c->i_);
}

void set_real(complex_t* c, double r)
{
	c->r_ = r;
}
	
void set_imag(complex_t* c, double i)
{
	c->i_ = i;
}

double get_real(complex_t* c)
{
	return c->r_;
}

double get_imag(complex_t* c)
{
	return c->i_;
}

double get_modulo(complex_t* c)
{
	return sqrt(c->r_ * c->r_ + c->i_ * c->i_);	
}

double get_fase(complex_t* c)
{
	return atan2(c->i_, c ->r_);	
}

complex_t suma(complex_t* c1,complex_t* c2)
{
	complex_t aux;

	aux.r_ = c1->r_ + c2->r_;
	aux.i_ = c1->i_ + c2->i_;

	return aux;
}
```




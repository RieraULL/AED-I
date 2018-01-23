# Programación Orientada a Objetos

La [Programación Orientada a Objetos (OOP)](https://en.wikipedia.org/wiki/Object-oriented_programming) es un [paradigma de programación](https://en.wikipedia.org/wiki/Programming_paradigm) que responde a ciertas propiedades. Entre ellas está la [encapsulación](https://en.wikipedia.org/wiki/Encapsulation_(computer_programming)), [abstracción](https://en.wikipedia.org/wiki/Abstraction_principle_(computer_programming), y algunas otras que se abordarán más adelanta. 

Con el fin de implementar estas propiedades algunos lenguajes de programación disponen de ciertos instrumentos que lo facilitan. Aunque estas propiedades también se pueden implementar sin hacer uso de un lenguaje de programación orientado a objetos.

Uno de los elementos fundamentales de la OOP son las clases.


## Clases

Una [clase](https://en.wikipedia.org/wiki/Class_(computer_programming)) es, en esencia, la definición de un tipo de dato complejo. En ocasiones se implementa como una estructura que permite la descripción de las características (atributos) y comportamiento (métodos) de un conjunto de objetos. Las clases, como habíamos mencionado anteriormente pueden implementarse en casi cualquier lenguaje de programación. 

El siguiente [fragmento de código](complex/complex.c) en lenguaje C persigue crear un nuevo tipo de dato denominado `complex_t`, que representa un número complejo y algunas de sus operaciones asociadas. El lenguaje C no es orientado a objetos, pero aún así hemos podido implementar esta característica de la OOP.

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

complex_t suma(complex_t* c1,complex_t* c2)
{
	complex_t aux;

	aux.r_ = c1->r_ + c2->r_;
	aux.i_ = c1->i_ + c2->i_;

	return aux;
}
```

Si estudiamos este [fragmento de código](complex/complex.c) podremos observar que persigue describir un nuevo tipo de dato para representar números complejos. Asimismo, se definen ciertas operaciones sobre números complejos. Tengamos en cuenta que las operaciones sobre números complejos sólo se llevarán a cabo sobre este tipo de dato, por lo que resulta natural aglutinarlas en torno a él. Además, se definen una serie de procedimientos que nos permiten acceder para manipular, o simplemente observar, el contenido de una variable que hayamos definido del tipo `complex_t`.

**Actividad**: compila y ejecuta el siguiente [fragmento de código](complex/complex.c). Observa el resultado.



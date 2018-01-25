# Programación Orientada a Objetos

La [Programación Orientada a Objetos (OOP)](https://en.wikipedia.org/wiki/Object-oriented_programming) es un [paradigma de programación](https://en.wikipedia.org/wiki/Programming_paradigm) que responde a propiedades como la [*abstracción*](https://en.wikipedia.org/wiki/Abstraction_principle_(computer_programming)), la [*encapsulación*](https://en.wikipedia.org/wiki/Encapsulation_(computer_programming)), [*sobrecarga de funciones*](https://en.wikipedia.org/wiki/Function_overloading), y otras que se abordarán más adelante. 

La **abstracción** persigue separar el *uso* de un tipo de dato de su *implementación*. Por ejemplo, supongamos que tenemos un tipo de dato que almacena una [imagen digital](https://en.wikipedia.org/wiki/Digital_image); podremos hacer usos de procedimientos que nos permitan visualizar la imagen, rotarla, hacer zoom en alguna zona. El usuario de ese tipo de dato es ajeno a que una imagen se [representa internamente](https://en.wikipedia.org/wiki/Raster_graphics) como una matriz de puntos, donde cada punto corresponde a tres números para la codificación [RGB](https://en.wikipedia.org/wiki/RGB_color_model)

Para poder implementar la abstracción los lenguajes orientados a objetos hacen uso de la **encapsulación** y la *ocultación de información*. Esto es, de mecanismos del lenguaje que permiten especificar qué aspectos de un tipo de dato son visibles al usuario y cuáles no.

Si bien algunos lenguajes de programación disponen de ciertos instrumentos que facilitan la implementación de estas propiedades, no es necesario hacer uso de un lenguaje de programación orientado a objetos para poder utilizarlas.

Uno de los elementos fundamentales de la OOP son las clases.


## Clases

Una [*clase*](https://en.wikipedia.org/wiki/Class_(computer_programming)) es, en esencia, la definición de un tipo de dato complejo. En ocasiones se implementa como una estructura que permite la descripción de las características (atributos) y comportamiento (métodos) de un conjunto de objetos. Las clases, como habíamos mencionado anteriormente pueden implementarse en casi cualquier lenguaje de programación.

El siguiente fragmento de [código](complex/complex_1.c) en lenguaje C persigue crear un nuevo tipo de dato denominado `complex_t`, que representa un número complejo y algunas de sus operaciones asociadas. El lenguaje C no es orientado a objetos, pero aún así hemos podido implementar esta característica de la OOP. A continuación se recoge un extracto.

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

Si estudiamos este fragmento de [código](complex/complex.c) podremos observar que persigue describir un nuevo tipo de dato para representar números complejos. Asimismo, se definen ciertas operaciones sobre números complejos. Tengamos en cuenta que las operaciones sobre números complejos sólo se llevarán a cabo sobre este tipo de dato, por lo que resulta natural aglutinarlas en torno a él. Además, se definen una serie de procedimientos que nos permiten acceder para manipular, o simplemente observar, el contenido de una variable que hayamos definido del tipo `complex_t`.

**Actividad**: compila y ejecuta el siguiente [fragmento de código](complex/complex.c). Observa el resultado y razona la ejecución.

### Declaración de una clase

A continuación, veamos cómo se implementa una clase similar en un lenguaje orientado a objetos como es el C++. Como habíamos indicado anteriormente, una clase define un tipo de datos. Las variables que son definidas con una clase se llaman *objetos*, aunque la nomenclatura en OOP (y en otras disciplinas) depende del autor.

```cpp
class complex_t {
private:
	double r_;
	double i_;

public:

	complex_t(double r,double i);
	complex_t(void);

	~complex_t(void);

	void imprime_complejo(ostream& os) const;

	void set_real(double r);
	void set_imag(double i);

	double get_real(void)   const;
	double get_imag(void)   const;
	double get_modulo(void) const;
	double get_fase(void)   const;
};

```
Este fragmento de [código](complex.cpp) corresponde con una descripción de un tipo de dato para representar un número complejo, similar al ejemplo anterior. La definición de una clase viene precedida por la palabra reservada `class` seguida del nombre de la clase. El cuerpo de la definición está delimitado por los símbolos `{` y `};`. Igual que en el caso anterior se definirá una estructura que representa un número complejo por sendos valores de tipo `double`, refiriéndose a la parte real y imaginaria mendiante `r_` e `i_`, respectivamente.

El cuerpo de una clase puede contener distintos tipos de elementos: 

- claúsulas 
- atributos
- y métodos

Con el fin de delimitar aquellos elementos de la clase ajenos al usuario, y aquellos otros que, sin embargo, podrá invocar el usuario se utiliza las **claúsulas** `private:` y `public:` respectivamente. De esta manera, el usuario que utilice este tipo de dato (`complex_t`) no podrá acceder a los elementos `r`_ e `i_`, pero sí a los procedimientos que se definen a continuación de la claúsula `public:`.


Las características de una clase (y por tanto de los objetos definidos mediante el tipo de dato que representa esa clase) vienen descritas por los **atributos**. Estos consisten en una secuencia de identificadores precedidos por un tipo de dato. En nuestro ejemplo los atributos son los identificadores `r_`  e `i_`, que representarán la parte real e imaginaria, respectivamente, de un número complejo. Nótese que en este caso los identificadores acaban con el símbolo guión bajo `_`: se trata de un convenio que persigue el diseño un código fuente más claro, diferenciando las variables ordinarias de los atributos de una clase meidante este símbolo. Algunos autores prefieren utilizar este símbolo simultáneamente como prefijo y sufijo de los identificadores de los atributos, o incluso únicamente como prefijo. En estas notas optaremos por seguir el convenio adelantado en el fragmento de código anterior.

Los **métodos** son las funciones que permiten alterar o extraer las características de un objeto. Los valores concretos de los parámetros que pasamos a un método se denominan [*mensajes*](https://en.wikipedia.org/wiki/Message_passing). En el fragmento de código anterior se observa que se declaran ciertos procedimientos para modificar el valor de algún atributo (aquellos cuyo nombre contiene el prefijo `set_`), y funciones para leer las características del objeto (aquellas funciones cuyo nombre contiene el prefijo `get_`). Aunque preceder el nombre de este tipo de métodos (métodos de acceso a los atributos) por los prefijos `set_` y `get_` no es en absoluto obligatorio, está bastante extendido su uso. 

Puede darse el caso de que un método admita varios tipos de mensaje. Esto se debe a una de las propiedades de la OOP que se había mencionado anteriormente: **sobrecarga de funciones**. A efectos de implementación esto supone que dos métodos diferentes pueden tener la misma denominación, pero han de requerir distinto número y/o tipo de parámetros.

Observamos también que los cuatro últimos métodos declarados en el fragmento de código anterior acaban con la palabra reservada `const`. Esta palabra reservada se utilia para identificar aquellos métodos que no modificarán las características de un objeto, es decir, que no nodificarán los atributos. Así, estos métodos suelen utilizarse para leer  los contenidos de los atributos, y no para modificarlos.

Existen familias de métodos especiales. Es el caso de los **constructores** y del **destructor**. Los constructores son una familia de métodos que permiten incializar un objeto durante su declaración. Se caracterizan porque se denominan igual que el identificador de la clase. En el fragmento de código anterior, gracias a la sobrecarga de funciones, se definen dos constructores. El primer constructor requiere de dos parámetros, mientras que el segundo no requiere parámetro alguno. Los constructores que no requieren parámetros se denominan constructores por defecto.

El destructor es un único método que tiene como propósito efectuar todas aquellas tareas requeridas después de que un objeto de esa clase deje de existir. Este tipo de métodos suele estar relacionado con la memoria dinámica. En ocasiones hay objetos que durante su construcción requieren de la reserva de memoria dinámica, así que el destructor llevaría a cabo las tareas de liberación de esta memoria cuando el objeto, al dejar de exisitir, no necesite esa memoria reservada.

El fragmento de código anterior contiene únicamente la declaración de los *atributos* y *métodos* que formarán parte de esta clase (`complex_t`). La implementación de los métodos, es decir, la definición de las acciones que llevarán a cabo, se efectuará en este caso durante un estadío posterior. 

### Implementación de una clase

Una vez hecha la declaración de los atributos y métodos, corresponde describir la **implementación de los métodos**, es decir, especificar qué operaciones lleva a cabo cada método. Esta implementación puede especificarse de diversas maneras. Una de ellas podría consistir en llevarla a cabo dentro de la propia declaración del método. Otra de las manera podría ser especificarla después de la definición de la clase, en un fichero aparte, o en el mismo fichero.

Veamos un ejemplo de este segundo caso. 

```cpp
void complex_t::set_real(double r)
{
	r_=r;
}

void complex_t::set_imag(double i)
{
	i_=i;
}

double complex_t::get_real(void) const
{
	return r_;
}

double complex_t::get_imag(void) const
{
	return i_;
}
```
Cuando la implementación se especifica fuera de la propia clase la implementación de los métodos se lleva a cabo tal y como se suele especificar un procedimiento ordinario en lenguaje C, aunque el nombre del método debe ir precedido del nombre de la clase a la que pertenece, y separado por los símbolos `::`. En este ejemplo, los métodos `set_real` y `set_imag` modifican la parte real e imaginaria de un objeto declarado con el tipo `complex_t`, respectivamente. Por otro lado, los métodos `get_real` y `get_imag` devuelven, respectivamente, los valores de la parte real e imaginaria de los objetos que los invocan. Recuérdese que el sufijo `const` después del nombre del método hace referencia a que dicho método no modificará el contenido del objeto.


A continuación se muestra el fragmento de código correspondiente a la implementación de los dos constructores y del destructor.

```cpp
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
	cout << "-- Bye, bye, complex! --" << endl;
}

```

La implementación del primer constructor inicializa la parte real y la parte imaginaria de un objeto definido con el tipo `complex_t` con el mensaje pasado a través de los parámetros `r`e `i`, respectivamente. Sin embargo, el constructor por defecto, inicializa los atributos con el valor `0`.  Finalmente, el destructor muestra por pantalla un texto de despedida.


```cpp
int main(void)
{
	complex_t a(1,2), b(2,3), c(3,4), d;

	cout << endl;
	a.imprime_complejo(cout);
	cout << endl;
	b.imprime_complejo(cout);
	cout << endl;
	c.imprime_complejo(cout);
	cout << endl;
	d.imprime_complejo(cout);
	cout << endl;
	cout << endl;

	/* a.r_ = 5; ERROR */
}
```

Se puede observar en la primera declaración cómo se declaran las variables `a`, `b`, `c`  y `d`. Es esta misma línea también observamos dos tipos de declaraciones: 

 - declaraciones con parámetros `a(1,2), b(2,3), c(3,4)`
 - declaraciones sin parámetros  `d`
 
Este detalle nos permite introducir el concepto de *constructor*. Los constructores son procedimientos  

[paso de mensajes](https://en.wikipedia.org/wiki/Message_passing)

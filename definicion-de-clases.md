# Declarando una clase

Ref. [code](code/code1.cpp)

A continuación, veamos cómo se declara una clase similar a la definida en la sección anterior en un lenguaje orientado a objetos como es el C++. Como habíamos indicado anteriormente, una clase define un tipo de dato. En este caso particular vamos a definir la clase `complex_t`, que representa un tipo de dato que almacena un [número complejo](https://es.wikipedia.org/wiki/Número_complejo).

El siguiente código 

```cpp
class complex_t {

private:

    double r_;
    double i_;

public:

    complex_t(double r,double i);
    complex_t(void);

    ~complex_t(void);

    void write_cartesian(ostream& os) const;
    void write_polar(ostream& os) const;

    void set_real(double r);
    void set_imag(double i);

    double get_real(void) const;
    double get_imag(void) const;

    void get(complex_t& c) const;
    void set(const complex_t& c);

private:

    double get_mod(void) const;
    double get_phase(void) const;
};
```

La definición de una clase viene precedida por la palabra reservada `class` seguida del nombre de la clase, en este caso `complex_t`. El cuerpo de la definición está delimitado por los símbolos `{` y `};`. Igual que en el caso anterior se definirá una estructura que representa un número complejo por sendos valores de tipo `double`, refiriéndose a la parte real y imaginaria mendiante `r_` e `i_`, respectivamente.

El cuerpo de una clase puede contener distintos tipos de elementos:

* claúsulas 
* atributos
* y métodos

Con el fin de delimitar aquellos elementos de la clase ajenos al usuario, y aquellos otros que, sin embargo, podrá invocar el usuario se utiliza las **claúsulas** `private:` y `public:` respectivamente. De esta manera, el usuario que utilice este tipo de dato \(`complex_t`\) no podrá acceder a los elementos `r_` e `i_`, ni a las funciones`get\_mod`o`get\_phase`, pero sí a las funciones que se definen a continuación de la claúsula`public:\`.

Las características de una clase \(y por tanto de los objetos definidos mediante el tipo de dato que representa esa clase\) vienen descritas por los **atributos**. Estos consisten en una secuencia de identificadores precedidos por un tipo de dato. En nuestro ejemplo los atributos son los identificadores `r_`  e `i_`, que representarán la parte real e imaginaria, respectivamente, de un número complejo. Nótese que en esta versión de la clase los identificadores acaban con el símbolo guión bajo `_`: se trata de un convenio que persigue el diseño un código fuente más claro, diferenciando las variables ordinarias de los atributos de una clase meidante este símbolo. Algunos autores prefieren utilizar este símbolo simultáneamente como prefijo y sufijo de los identificadores de los atributos, o incluso únicamente como prefijo. En estas notas optaremos por seguir el convenio adelantado en el fragmento de código anterior.

Los **métodos** son las funciones que permiten alterar o extraer las características de un objeto. Los valores concretos de los parámetros que pasamos a un método se denominan [_mensajes_](https://en.wikipedia.org/wiki/Message_passing). En el fragmento de código anterior se observa que se declaran ciertos procedimientos para modificar el valor de algún atributo \(aquellos cuyo nombre contiene el prefijo `set_`\), y funciones para leer las características del objeto \(aquellas funciones cuyo nombre contiene el prefijo `get_`\). Aunque preceder el nombre de este tipo de métodos \(métodos de acceso a los atributos\) por los prefijos `set_` y `get_` no es en absoluto obligatorio, está bastante extendido su uso. En ocasiones se declaran métodos privados, que serán utilizados como herramientas de otros métodos. Así, la única manera de _comunicarnos_ con un objeto es a través de los métodos públicos. El conjunto de métodos públicos que nos permite modificar o leer el _estado_ de un objeto se denomina **interfaz**.

Puede darse el caso de que un método admita varios tipos de mensaje. Esto se debe a una de las propiedades de la OOP que se había mencionado anteriormente: **sobrecarga de funciones**. A efectos de implementación esto supone que dos métodos diferentes pueden tener la misma denominación, pero han de requerir distinto número y/o tipo de parámetros.

Observamos también que los cuatro últimos métodos declarados en el fragmento de código anterior acaban con la palabra reservada `const`. Esta palabra reservada se utilia para identificar aquellos métodos que no modificarán las características de un objeto, es decir, que no nodificarán los atributos. Así, estos métodos suelen utilizarse para leer  los contenidos de los atributos, y no para modificarlos.

Existen familias de métodos especiales. Es el caso de los **constructores** y del **destructor**. Los constructores son una familia de métodos que permiten incializar un objeto durante su declaración. Se caracterizan porque se denominan igual que el identificador de la clase. En el fragmento de código anterior, gracias a la sobrecarga de funciones, se definen dos constructores. El primer constructor requiere de dos parámetros, mientras que el segundo no requiere parámetro alguno. Los constructores que no requieren parámetros se denominan constructores por defecto.

El destructor es un único método que tiene como propósito efectuar todas aquellas tareas requeridas después de que un objeto de esa clase deje de existir. Este tipo de métodos suele estar relacionado con la memoria dinámica. En ocasiones hay objetos que durante su construcción requieren de la reserva de memoria dinámica, así que el destructor llevaría a cabo las tareas de liberación de esta memoria cuando el objeto, al dejar de exisitir, no necesite esa memoria reservada.

El fragmento de código anterior contiene únicamente la declaración de los _atributos_ y _métodos_ que formarán parte de esta clase \(`complex_t`\). La implementación de los métodos, es decir, la definición de las acciones que llevarán a cabo, se efectuará en este caso durante un estadío posterior.




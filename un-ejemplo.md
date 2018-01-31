#Un ejemplo de una clase compleja

Ref. [code1a](https://github.com/RieraULL/AED-ULL/blob/master/vector/vector1/vector_t.hpp)
Ref. [code1b](https://github.com/RieraULL/AED-ULL/blob/master/vector/vector1/vector_t.cpp)
Ref. [code1c](https://github.com/RieraULL/AED-ULL/blob/master/vector/vector1/main.cpp)

Ref. [code2a](https://github.com/RieraULL/AED-ULL/blob/master/vector/vector2/vector_t.hpp)
Ref. [code2b](https://github.com/RieraULL/AED-ULL/blob/master/vector/vector2/vector_t.cpp)
Ref. [code2c](https://github.com/RieraULL/AED-ULL/blob/master/vector/vector2/main.cpp)

A continuación se describe una clase que representa un tipo de dato algo más complejo de lo que hemos visto hasta el momento. Se trata de un clase que representa un vector cuyos elementos son de tipo `double`. En esta ocasión el código se presenta en tres ficheros. Un primer fichero `vector_t.hpp` en el que se incluye únicamente la declaración de la clase `vector_t`; un segundo fichero `vector_t.cpp` en el que se incluye la implementación de los métodos de la clase `vector_t`; y un último fichero `main.cpp` en el que se incluye el programa principal de nuestro sencillo programa. 

Estos tres ficheros deben compilarse con la llamada:
~~~
g++ -g main.cpp vector_t.cpp -o vector
~~~

El siguiente fragmento de código recoge la declaración de la clase, así como de dos operadores de entrada y salida.

~~~cpp
class vector_t{

  private:

    double* base_;
    size_t  sz_;

  public:

    vector_t(void);
    vector_t(size_t sz);
    vector_t(const vector_t& v);
    ~vector_t(void);
    
    void resize(size_t sz);
    
    size_t  size(void) const;
    double& at(size_t i);
    double  at(size_t i) const;
    
    ostream& write(ostream& os) const;
    istream& read(istream& is);
        
    double& operator[](size_t i);
    double  operator[](size_t i) const;
    
  private:
    void build(size_t sz);
    void destroy(void);
    
};

ostream& operator<<(ostream& os, const vector_t& v);
istream& operator>>(istream& is, vector_t& v);
~~~

Como se puede observar esta clase define un tipo de dato que representa un vector. Tal y como ya habíamos avanzado en nuestra introducción sobre [punteros](punteros.md) un vector es en realidad una región de memoria de un tamaño determinado, que se ha reservado previamente, y accesible mediante un puntero. Por ello, la clase vector de nuestro ejemplo va a estar caracterizado por dos atributos: un puntero a la base del vector `base_`, y el tamaño del vector `sz_`. Aunque no es extrictamente necesario conocer el tamaño del vector, resulta conveniente con el fin de evitar desbordamientos en el acceso.

Vamos a crear tres constructores:

- Un constructor por defecto, que crea un vector de tamaño nulo. Para poder utilizar este vector podremos hacer uso del método `resize`, que permite cambiar el tamaño de nuestro vector.
- Un constructor al que se le pasa como parámetro el tamaño del vector.
- Y un constructor de copia. 

En este caso es de gran importancia llevar a cabo un constructor de copia, ya que, como habíamos adelantado en secciones anteriores, el constructor de copia que crea el compilador por defecto en el objeto receptor los atributos del objeto original. Esto supone que si llevamos a cabo una llamda de este tipo

~~~cpp
	vector_t a(5);
	vector_t b(a);
~~~

el vector `a` puede que tenga en sus atributos los valores `(0xA1B34, 5)`. Así que al crear el vector `b` lo inicializaremos con el mismo contenido `(0xA1B34, 5)`. El gran inconveniente es que ambos vectores comparten la misma dirección base, por lo que si introducimos un elemento en el vector `a`:

~~~cpp 
	a[5] = 8;
~~~

habrá también un `8` almacenado en la posición 5.

Por esta razón el constructor de copia que diseñemos debe reservar una región de memoria para `b` independiente de la región utilizada por el vector `a`.

Dentro de la familia de métodos podemos encontrar:

- un método `resize` para cambiar el tamaño del vector,
- un método `size` que devuelve el tamaño del vector,
- dos métodos `at` de acceso, uno de ellos para el caso de un objeto constante,
- dos métodos de entrada/salida,
- dos sobrecargas del operador `[]`,
- y dos métodos privados que gestionan la reserva y liberación de memoria.

Se muestra a continuación la implementación de dos constructores y el destructor.

~~~cpp
vector_t::vector_t(void):
base_(NULL),
sz_(0)
{}

vector_t::vector_t(size_t sz):
base_(NULL),
sz_(sz)
{
    build(sz_);
}

vector_t::~vector_t(void)
{
    destroy();
}

void vector_t::build(size_t sz)
{
    base_ = new double [sz];
}

void vector_t::destroy(void)
{
    if (base_ != NULL){

        delete [] base_;
        base_ = NULL;
    }
}
~~~

El segundo de los constructores llama al procedimiento privado `build` para reservar la memoria que requiere. Por otro lado, el destructor invoca al método privado `destroy`. Este último método libera la memoria apunta por `base_` en caso de que tuviera memoria asignada.

De igual manera, el método `resize` hace uso de estos dos métodos privados.

~~~cpp
void vector_t::resize(size_t sz)
{
    destroy();
    sz_ = sz;
    build(sz_);
}
~~~

Nótese que esta versión del método `resize` no preserva los datos que estaban almacenados previamente en el vector. ¿Cómo modificarías la implementación de este método para que se preservara el contenido?


Veamos a continuación la implementacón de los métodos de acceso:

~~~cpp
double& vector_t::at(size_t i)
{
	assert(i < sz_);

    return base_[i];
}

double vector_t::at(size_t i) const
{
	assert(i < sz_);

    return base_[i];
}
~~~

Como se puede observar, se hace referencia a la función `assert`. Esta función tiene como propósito efectuar una parada de la ejecución del programa en caso de que no se verifique la condición que se pasa como parámetro. Esta función de muy útil para verificar que los valores de determinadas variables, durante la ejecución del programa, debe cumplir ciertas condiciones. En caso de que no sea así, la ejecución se detiene, se muestra un mensaje de error indicando la línea de código en la que se ha producido el error de ejecución.

Si quiere ver cómo funciona, prueba a acceder a una posición del vector posterior al tamaño del mismo.

Los métodos de sobrecarga del operador `[]` hacen referencia a los métodos de acceso reseñados anteriormente.

~~~cpp
double& vector_t::operator[](size_t i)
{
    return at(i);
}

double vector_t::operator[](size_t i) const
{
    return at(i);
}
~~~


Los siguiente métodos de entrada salida tienen como propósito la escritura y la lectura, respectivamente, de un vector en/desde fichero.

~~~cpp
ostream& vector_t::write(ostream& os) const
{
    os << setw(8) << sz_ << endl;
    
    for(int i = 0; i < sz_; i++)
        os << setw(8) << fixed << setprecision(4) << base_[i] << " ";
        
    os << endl;
}

istream& vector_t::read(istream& is)
{
    is >> sz_;
    
    resize(sz_);
    
    for(int i = 0; i < sz_; i++)
        is >> base_[i];
}
~~~



## Actividades propuestas

1. Modifica la clase vector para que incluya, además de los constructores actuales, un constructor 
~~~cpp
	vector_t(int a, int b);
~~~
que permita indexar el vector en el rango [a, b]. Permitiendo accesos como éste:
~~~cpp
	vector_t a(-10, -1);

	a[-5] = 4;
~~~
:boom: Pista: Se deben cambiar los atributos, incluso de tipo de dato.


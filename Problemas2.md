# Problemas resueltos II

## Problema 1

### Enunciado
Construir una clase `point_t` que represente un punto en el plano euclídeo en dos dimensiones. Esta clase debe estar caracterizada por las coordenadas del punto. Constrúyase asimismo una clase `line_eq_t` que represente una [recta](https://es.wikipedia.org/wiki/Recta) en el plano euclídeo, caracterizada por la pendiente y la ordenada al origen. Ambas clases deben tener sendos métodos que calculen la distancia euclídea desde un punto a la respectiva estructura. Es decir, la clase `point_t` debe tener un método que devuelva la [distancia](https://es.wikipedia.org/wiki/Distancia_euclidiana) del punto invocante al punto que se pasa como mensaje, y la clase `line_eq_t` debe tener un método que devuelva la [distancia](https://es.wikipedia.org/wiki/Distancia_de_un_punto_a_una_recta) de la recta invocante al punto que se pasa como mensaje.

### Solución

Ref1. [Prob1](prob2/point_t.hpp)
Ref2. [Prob1](prob2/line_eq_t.hpp)
Ref3. [Prob1](prob2/prob1.cpp)

Hemos codificado este problema mediante tres ficheros: un fichero de cabecera para cada una de las clases que definimos ([`point_t`](prob2/point_t.hpp) y [`line_eq_t`](prob2/line_eq_t.hpp)), y un [programa principal](prob2/prob1.cpp) en el que se muestra algunas de las funcionalidades de las clases definidas.

En primer lugar declaramos e implementamos la clase `point_t`. En esta ocasión mostramos una manera alternativa de efectuar las implementaciones dentro de la declaración de la clase.

~~~cpp
class point_t {
private:
	double x_;
	double y_;

public:
	point_t(void):
	x_(0),
	y_(0) {}

	point_t(double x, double y):
	x_(x),
	y_(y) {}

	~point_t(void) {}

	double get_x(void) const {return x_;} 
	double get_y(void) const {return y_;}

	void set(double x, double y) {
	
		x_ = x;
		y_ = y;
	}

	void write(ostream& os) const {

		os << "(";
		os << setw(6) << fixed << setprecision(2) << x_;
		os << ",";
		os << setw(6) << fixed << setprecision(2) << y_;
		os << ")";
	}

	double distance_L2(const point_t& p)
	{
		return sqrt((p.x_ - x_) * (p.x_ - x_) + (p.y_ - y_) * (p.y_ - y_));
	}

	double distance_L1(const point_t& p)
	{
		return fabs(p.x_ - x_) + fabs(p.y_ - y_);
	}
};
~~~ 

Esta clase viene caracterizada por las dos coordenadas, para las cuales hemos optado por dos atributos de tipo `double`. Definimos dos constructores y el destructor. Uno de los constructores es un constructor por defecto.

Definimos e implementamos métodos de acceso y manipulación (`get_x`, `get_y` y `set`), un método para salida a través de un *stream* de salida, y dos métodos para el cálculo de la distancia a un punto que se pasa como parámetro. Hemos optado por un método que devuelve la distancia euclídea (`distance_L2`), y otro que devuelve la distancia de Manhatan (`distance_L1`). 

Seguidamente definimos la clase que representa una recta caracterizada por la pendiente y la ordenada al origen.

~~~cpp
class line_equ_t {
    private:
        double m_;
        double c_;
        
    public:
    line_equ_t (void):
        m_(0),
        c_(0) {}
        
   line_equ_t (double m, double c):
        m_(m),
        c_(c) {}   

   line_equ_t (const point_t& p1, const point_t& p2):
        m_(0),
        c_(0) 
	{            
            m_ = (p2.get_y() - p1.get_y()) / (p2.get_x() - p1.get_x());
            c_ = -p1.get_x() * m_ + p2.get_y();
    }

	~line_equ_t (void) {}  

	double get_m(void) const {return m_;}
	double get_c(void) const {return c_;}

	void set(double m, double c)
	{
		m_= m;
		c_= c; 
	}

	void write(ostream& os) const
	{
		os << "y = ";
		os << setw(6) << fixed << setprecision(2) << m_;
		os << "x + ";
		os << setw(6) << fixed << setprecision(2) << c_;
	} 
	
   double distance(const point_t& p) const
   {
      const double d = fabs(m_* p.get_x() - p.get_y() + c_)/sqrt(m_ * m_ + 1);
      return d;
    }
     
};
~~~

Esta clase está caracterizada por la pendiente `m_`  y la ordenada al origen `c_`. Contiene tres constructores y un destructor. Uno de los constructores es un constructor por defecto, otro construye el objeto a partir de la pendiente y la ordenada al origen, y un último constructor construye el objeto a partir de dos puntos.

En esta implementación hemos incluido métodos de acceso y manipulación, así como un método para mostrar por pantalla la descripción de la recta.

Finalmente se define e implementa la función de distancia de la recta invocante al punto que se pasa como parámetro.

Finalmente se ha implementado un breve programa principal.

~~~cpp
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
~~~

En el programa principal se definen dos puntos y una recta, mostrándose por pantalla la distancia de la recta a ambos puntos.

## Problema 2

### Enunciado

Construir una clase `vector_t` que represente un tipo de dato vector indexado en entre sus límites izquierdo y derecho. Impleméntese, asimismo, un procedimiento que sume dos vectores de este tipo, dando lugar a un nuevo vector que tiene como límite izquierdo el menor de los límites izquierdos de los vectores a sumar, y como límite derecho el mayor de los límites derechos. 

### Solución

Véase una posible solución en [Prob2](prob2/bounded_vector.cpp)

## Problema 3

### Enunciado

### Triángulo de Pascal y números combinatorios

El objetivo de esta problema es construir un solucionador de números combinatorios a partir del Triángulo de Pascal [2].

La estructura fundamental para abordar el problema es una clase que represente un Triángulo de Pascal. Denominaremos a esta clase `pascal_triangle_t`.

Desarrollaremos el problema en tres fases.
#### Fase I: Desarrollo de la clase `vector_t`

Para empezar a construir la clase `pascal_triangle_t` necesitaremos una estructura auxiliar tipo vector, y con ese fin construiremos una clase denominada `vector_t`. Podremos hacer uso de la clase `vector_t` que se encuentra en nuestras notas de clase (puedes encontrar esta clase comentada en el enlace [1]), siempre y cuando comprendamos correctamente su funcionamiento. El vector almacenará elementos de tipo `binomial_number_t`. El tipo de dato `binomial_number_t` se definirá de la siguiente manera:

~~~cpp
typedef unsigned long binomial_number_t;
~~~

Es decir, se redefine un entero largo sin signo.


#### Fase II: Desarrollo de la clase `pascal_triangle_t`

Representaremos el triángulo sobre un vector. Para ello, debemos encontrar una correspondencia entre cada elemento `(i , j)` del Triángulo de Pascal, y su posición correspondiente `k` en el vector sobre el que se almacenará.

Veamos un ejemplo de Triángulo de Pascal de 6 niveles:
~~~
   1  
   1   1
   1   2   1
   1   3   3   1
   1   4   6   4   1
   1   5  10  10   5   1
~~~

Este triángulo se almacenará en un vector de la siguiente manera:

~~~
 1  1  1  1  2  1  1  3  3  1  1  4  6  4  1  1 5 10 10 5 1
~~~

Es decir, un nivel tras otro, de forma consecutiva.

El Triángulo de Pascal está caracterizado también por el número de niveles que almacena. Por lo tanto la clase `pascal_triangle_t` contendrá como atributos un vector de elementos del tipo `binomial_number_t` (véase fase anterior), y un entero sin signo denotando el número de niveles del triángulo. De esta manera, La sección de los atributos podría quedar de la siguiente manera:

~~~cpp
private:
        vector_t    v_;
        const size_t n_;
~~~

Una vez definidos, en la sección private, los dos atributos que constituyen la clase `pascal_triangle_t` debemos definir en la sección pública el constructor y el destructor.

El constructor, al que le pasaremos como parámetro el número de niveles del triángulo `n`, debe inicializar el atributo `n_` y construir el vector asociado al triángulo.

El nivel i−ésimo el triángulo tendrá `i` elementos. De esa manera, si queremos construir un vector que considere un número máximo `n`, nuestro vector debe tener el tamaño `1 + 2 + ... + n`. Es decir la suma de la serie anterior.

Con el propósito de hacer este cálculo en el constructor, y en estadíos posteriores de nuestro trabajo, desarrollaremos un método privado de la clase `pascal_triangle_t` (que podríamos denominar `size_t S(size_t k)` que devuelva la suma de `k` primeros elementos de una serie.

De esta manera, inicializaremos la longitud del vector, es decir el constructor del vector, con el valor devuelto por `S(n)`.

La construcción del triángulo implica rellenarlo con los valores adecuados. Para ello, téngase en cuenta que la entrada `(i,j)`
del triángulo es el resultado de la suma de las entradas `(i − 1,j − 1) + (i − 1, j)`.

La clase pascal_triangle_t deberá contener un método `binomial_number_t at(size_t i, size_t j) const` que devuelva el valor del triángulo en cualquier posición válida del mismo. Si la posición no fuera válida, debe mostrar un mensaje de error.

Adicionalmente, se debe incluir un procedimiento que muestre por pantalla el triángulo. De esta manera, el alumno será capaz de comprobar si ha sido construido de forma correcta.

En suma, deberíamos incluir los siguiente métodos:

~~~cpp
public:
      pascal_triangle_t(size_t n);
      ~pascal_triangle_t(void);
      
      void write(ostream& os) const;
      binomial_number_t at(size_t i, size_t j) const;

private:
      size_t pos(size_t i, size_t j) const;
      inline size_t S(size_t n) const;
~~~

#### Fase III: Desarrollo de la clase `binomial_t`

Nótese que el nivel i−ésimo de este triángulo nos permitirá calcular los números combinatorios del número `i − 1`. Es decir, para el caso del octavo nivel, el primer elemento corresponde a `C(7,0)`, el segundo a `C(7,1)`, el tercero a `C(7,2)`, y así sucesivamente. Léase el artículo [2] para más detalle.

Una vez definida e implementada la clase `pascal_triangle_t` declararemos e implementaremos la clase `binomial_t`. Esta clase tendrá como único atributo un elemento de la clase `pascal_triangle_t` de la siguiente manera:

~~~cpp
class binomial_t
{
private:
      pascal_triangle_t T_;
~~~

El constructor debe indicar el número máximo para el cual se quiere calcular un número combinatorio. Y además del constructor y destructor, debe contener un método:

~~~cpp
binomial_number_t C(size_t i, size_t j) const
~~~

que devuelva el valor del número combinatorio.

Finalmente, se debe implementar un programa principal en el que muestre la funcionalidad de las clase.


Referencias

[1] https://github.com/RieraULL/AED-ULL/blob/master/un-ejemplo.md

[2] https://es.wikipedia.org/wiki/Tri%C3%A1ngulo_de_Pascal


### Solución

Véase una posible solución en [Prob3](prob2/pascal.cpp)

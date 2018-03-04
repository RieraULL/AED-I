# Práctica #2

El objetivo de esta práctica es construir un resolutor de números combinatorios a partir del [Triángulo de Pascal](https://es.wikipedia.org/wiki/Tri%C3%A1ngulo_de_Pascal).

La estructura fundamental para abordar el problema es una clase que represente un *Triángulo de Pascal*. Denominaremos a esta clase ```pascal_triangle_t```.

Para empezar a construir la clase ```pascal_triangle_t```  necesitaremos una estructura auxiliar tipo vector, y con ese fin construiremos una clase denominada ```vector_t```. Podremos hacer uso de la clase ```vector_t``` que se encuentra en nuestras notas de clase (puedes encontrar esta clase comentada en el enlace [1]), siempre y cuando comprendamos correctamente su funcionamiento.

De manera similar al caso estudiado en la práctica anterior, en el que hemos representado una matriz bidimensional mediante un vector unidimensional, representaremos el triángulo subre un vector. Para ello, debemos encontrar una correspondencia entre cada elemento  ```(i,j)``` del Triángulo de Pascal, y su correspondencia ```k``` en el vector sobre el que se almacenará.

Veamos un ejemplo de Triángulo de Pascal. 

```
   1  
   1   1
   1   2   1
   1   3   3   1
   1   4   6   4   1
   1   5  10  10   5   1
   1   6  15  20  16   6  1
   1   7  21  35  35  21  7  1  
```
Nótese que el nivel i-ésimo de este triángulo nos permitirá calcular los números combinatorios del número i - 1. Es decir, para el caso de la octava fila, el primer elemento corresponde a C(7,0), el segundo a C(7,1), el tercero a C(7,2), y así sucesivamente. Léase el artículo [2] para más detalle.

El Triángulo de Pascal está caracterizado por el número de niveles que almacena. Por lo tanto la clase ```pascal_triangle_t``` contendrá como atributos un vector de elementos del tipo ```binomial_number_t```, y un entero sin signo denotando el número de niveles del triángulo. El tipo de dato ```binomial_number_t``` se definirá de la siguiente manera:

```cpp
typedef unsigned long binomial_number_t;
```
De esta manera, La sección de los atributos podría quedar de la siguiente manera

```cpp
private:
        vector_t    v_;
        const size_t n_;
```

Una vez definidos, en la sección ```private:```, los dos atributos que constituyen la clase ```pascal_triangle_t``` debemos definir en la sección pública el constructor y el destructor.

El constructor, al que le pasaremos como parámetro el número de niveles del triángulo ```n```, debe inicializar el atributo ```n_``` y construir el vector asociado al triángulo.

Como se puede ver en la primera figura del artículo de Wikipedia [2], si queremos construir un triángulo para un número ```n```, el triángulo debe tener ```n + 1``` niveles. Así en el nivel i-ésimo el triángulo tendrá i elementos. De esa manera, si queremos construir un vector que considere un número máximo n, nuestro vector debe tener el tamaño 1 + 2 + ... + n + (n + 1). Es decir la suma de la serie anterior. 

Con el propósito de hacer este cálculo en el constructor, y en estadíos posteriores de nuestro trabajo, desarrollaremos un método privado de la clase ```pascal_triangle_t``` (que podríamos denominar ``` size_t S(size_t k)``` que devuelva la suma de k primeros elementos de una serie.

De esta manera, inicializaremos la longitud del vector, es decir el constructor del vector con el valor devuelto por ```S(n)```.

Esta clase deberá contener un método ```binomial_number_t at(size_t i, size_t j) const``` que devuelva el valor del triángulo en cualquier posición válida del mismo. Si la posición no fuera válida, debe mostrar un mensaje de error.

Adicionalmente, se debe incluir un procedimiento que muestre por pantalla el triángulo. De esta manera, el alumno será capaz de comprobar si ha sido construido de forma correcta.

Una vez definida e implementada la clase ```pascal_triangle_t``` declararemos e implementaremos la clase ```combinatorial_t```. Esta clase tendrá como único atributo un elemento de la clase ```pascal_triangle_t```. El constructor debe indicar el número máximo para el cual se quiere calcular un número combinatorio. Y además del constructor y destructor, debe contener un método ```binomial_number_t C(size_t i, size_t j) const``` que devuelva el valor del número combinatorio.

Finalmente, se debe implementar un programa principal en el que muestre la funcionalidad de las clase.

## Evaluación

El alumno debe mostrar las clases ```vector_t```, ```pascal_triangle_t```, ```combinatorial_t```, junto con un programa principal mostrando la funcionalidad de las clases y funcionando sin errores. Todo el programa puede implementarse en un único fichero.

1. Para obtener una calificación de 6 el alumno debe llevar a cabo un cambio en la funcionalidad de su programa propuesto por el profesor.

2. Para obtener una calificación de 8 el alumno debe superado el punto anterior, y haber implementado el programa utilizando un fichero para cada clase y otro para el programa principal.

3. La posibilidad de obtener una calificación superior a 8 será evaluada por el profesor, teniendo en cuenta la calidad del código, capacidad para responder a preguntas o el desarrollo de funcionalidades adicionales más complejas.  

### Nota
1. El envío de una práctica a través del aula virtual no presupondrá su entrega. 

2. El objeto de la parte práctica de la asignatura es evaluar la capacidad y destreza del alumnado para resolver problemas mediante algoritmos. La realización del trabajo descrito en el enunciado es sólo uno de los aspectos a evaluar.

## Referencias 

[1] https://github.com/RieraULL/AED-ULL/blob/master/un-ejemplo.md

[2] https://es.wikipedia.org/wiki/Tri%C3%A1ngulo_de_Pascal
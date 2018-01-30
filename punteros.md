# Punteros en C y C++

Ref. [code1](https://github.com/RieraULL/AED-ULL/blob/master/code1/pointer1.c)
Ref. [code2](https://github.com/RieraULL/AED-ULL/blob/master/code1/pointer1.cpp)
Ref. [code3](https://github.com/RieraULL/AED-ULL/blob/master/code1/pointer2.c)
Ref. [code4](https://github.com/RieraULL/AED-ULL/blob/master/code1/pointer2.cpp)
Ref. [code5](https://github.com/RieraULL/AED-ULL/blob/master/code1/pointer3.c)
Ref. [code6](https://github.com/RieraULL/AED-ULL/blob/master/code1/pointer3.cpp)
Ref. [code7](https://github.com/RieraULL/AED-ULL/blob/master/code1/pointer4.c)
Ref. [code8](https://github.com/RieraULL/AED-ULL/blob/master/code1/pointer4.cpp)
Ref. [code9](https://github.com/RieraULL/AED-ULL/blob/master/code1/pointer5.c)
Ref. [code10](https://github.com/RieraULL/AED-ULL/blob/master/code1/pointer5.cpp)

## Introducción

Los punteros son extremadamente potentes porque le permiten acceder a direcciones y manipular sus contenidos. Pero también son extremadamente complejos de manejar. Utilizándolos correctamente, podrían mejorar en gran medida la eficiencia y el rendimiento. Por otro lado, su uso incorrecto podría generar muchos problemas, desde códigos no legibles y no actualizables, hasta errores difíciles de corregir, como fugas de memoria y desbordamiento de búfer, que pueden exponer el sistema a la piratería. Muchos lenguajes nuevos (como Java y C #) eliminan el puntero de su sintaxis para evitar las *trampas* de los punteros, proporcionando administración de memoria automática.

Cada posición de memoria tiene una *dirección* y contiene un dato. La dirección es un número (a menudo expresado en hexadecimal), que puede ser difícil de usar por los programadores. Depende exclusivamente del programador interpretar el significado de los datos, como números enteros, números reales, caracteres o cadenas.

Para facilitar la programación cuando se utiliza la dirección numérica los primeros lenguajes de programación  introdujeron el concepto de variables. Una variable es una ubicación con nombre que puede almacenar un valor de un tipo particular. En lugar de direcciones numéricas. Así,  nombres (o identificadores) se asocian a ciertas direcciones. Además, los tipos (como `int`, `double`, `char`) están asociados con los contenidos para facilitar la interpretación de los datos.

Una variable de puntero (o puntero) es básicamente una variable normalque pueden almacenar un dato. A diferencia de la variable normal que almacena un valor (como un `int`, un `double`, un `char`), un puntero almacena una dirección de memoria.

El siguiente ejemplo muestra la declaración y uso de dos punteros.

~~~cpp
int main(void){
	
 	int    a;
 	double b; 
 
 	int    *a_ptr = NULL; 
 	double *b_ptr = NULL;
 		
 	a = 5;
	b = 12.6; 
	
	a_ptr = &a; 
	b_ptr = &b; 

	cout << setw(4) << a << setw(16) <<  a_ptr << endl; 
	cout << setw(4) << fixed << setprecision(1) << b << setw(16) <<  b_ptr << endl; 
	cout << setw(4) << a << setw(16) << *a_ptr << endl;
	
	return 0;
}
~~~

Cuando se declara una variable puntero, su contenido no se inicializa. En otras palabras, contiene una dirección *basura*, que por supuesto no es una dirección válida. ¡**Esto es muy peligroso**! Debe inicializarse un puntero asignándole una dirección válida. Esto normalmente se realiza a través del operador de dirección (`&`), o asignándole el puntero nulo `NULL`.

El operador de *dirección* (`&`) opera en una variable y devuelve la dirección de la variable. Por ejemplo, si `a` es una variable `int`, `&a`devuelve la dirección de memoria de la variable.

El operador de *indirección* (o de *desreferenciación*) (`*`) opera en un puntero y devuelve el valor almacenado en la dirección guardada en la variable d puntero. Por ejemplo, si `a_ptr` es un puntero a `int`, `*a_ptr` devuelve el valor `int` apuntado `a_ptr`.


## Vectores y punteros

El siguiente fragmento de código muestra cómo los vectores definidos en C++ son en realidad punteros que apunta al comienzo de una región de memoria que ha sido reservada para almacenar datos uniformes.


~~~cpp
int main(void){
	
	int    a[MAXIMO];
 	double b[MAXIMO]; 
 	
	int    *a_ptr = NULL; 
 	double *b_ptr = NULL;
 	
 	a_ptr = a;
 	b_ptr = b;
	
	for(int i = 0; i < MAXIMO; i++)
	{
		a[i] = i;
		b[i] = i + 0.5;
	}

	for(int i = 0; i < MAXIMO; i++)
	{	
		cout << setw(4) << a[i] << setw(4) << *(a_ptr + i) << endl; 
		cout << setw(4) << a_ptr[i] << setw(4) << *(a + i) << endl; 
	}

	return 0;
}
~~~

Como se puede ver en el código anterior, se definen dos variables `a`y `b` como dos vectores de tamaño `MAXIMO`. Seguidamente se declaran dos variables tipo puntero `a_ptr` y `b_ptr`. A continuación se asigna `a` a `a_ptr` y  `b` a `b_ptr`. Esta asignación es posible porque los vectores en C++ son en realidad punteros. A continuación se rellenan ambos vectors con cierto contenido. 

El último bucle, en el que se recorren las estructuras para mostrar su contenido, se puede ver cómo se puede acceder a los elementos del vector utilizando la notación de punteros. Es decir, acceder a la posición `i` del vector a puede hacerse de dos maneras: 

- `a[i]`
- `*(a + i)`

El siguiente fragmento de código modifica el el contenido de un vector ¿Sabrías de antemano qué se va a mostrar por pantalla?

~~~cpp
int main(void){
	
	int numbers[MAXIMO];
 	
	int *p = NULL; 
	
	p = numbers;     *p = 10; 
	p ++;            *p = 20; 
	p = &numbers[2]; *p = 30; 
	p = numbers + 3; *p = 40; 
	p = numbers;     *(p+4) = 50;

	for(int i = 0; i < MAXIMO; i++)
		cout << setw(4) << numbers[i] << endl;				
}
~~~

## Operadores `new` y `delete`

En lugar de definir una variable `int` y asignar la dirección de la variable puntero `a_ptr` (`a_ptr = &a`), el almacenamiento puede asignarse dinámicamente en tiempo de ejecución, a través del operador `new`. En C++, cada vez que asigna un fragmento de memoria dinámicamente a través de `new`, de debe eliminar después de usar, (es decir, debe liberarse la memoria).

El operador `new` devuelve un puntero a la memoria reservada. El operador `delete` toma un puntero (que está apuntando a una región de memoria asignada a través de `new`) como único argumento.

El siguiente fragmento de código muestra dos ejemplos de utilización los operadores `new`y `delete`, en caso de que definamos un vector, o una variable individual. ¿Podrías advertir la diferencia en ambos casos?

~~~cpp
int main(void){
 		
	int a[MAXIMO];
	
	int *a_ptr = NULL; 
	int *b_ptr = NULL;

	a_ptr = new int [MAXIMO];
	b_ptr = new int;

	*b_ptr = 5;

	for(int i = 0; i < MAXIMO; i++)
	{
		a[i] = i;
		a_ptr[i] = i;
		cout << setw(4) << a[i] << setw(4) << a_ptr[i] << endl;
	}

	cout << setw(4) << *b_ptr << endl;
			
	delete [] a_ptr;	
	a_ptr = NULL;

	delete b_ptr;
   	b_ptr = NULL;
}
~~~


## Referencias sobre punteros en la *web*

- http://www.cplusplus.com/doc/tutorial/pointers/
- https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp4_PointerReference.html



# Declaración de objetos

Ref. [code](https://github.com/RieraULL/AED-ULL/blob/master/code/code1.cpp)

El siguiente fragmento de código recoge la declaración de varios objetos. Recordemos que un objeto es una variable cuyo tipo de dato es una clase. Por ello la declaración de un objeto se hace de forma similar a la declaración de una variable, pero con la diferencia de que la declaración debe invocar a uno de los destructores. En caso de que se invoque al constructor por defecto, no hay que especificar paréntesis. Veamos un ejemplo de declaración de objetos.

```cpp
int main(void)
{
    complex_t a(1, 2), b(2, 3), c(3, 4), d;
```

La primera línea de este procedimiento principal declara las objetos `a`, `b`, `c`  y `d`. Observamos dos tipos de declaraciones:

1. declaraciones con parámetros `a(1, 2), b(2, 3), c(3, 4)`
2. declaraciones sin parámetros  `d`

En el primer caso los objetos invocan al constructor que requiere dos parámetros. Así el objeto `a` se inicializa con el mensaje `(1, 2)`, que hará que el constructor inicialice los atributos correspondientes al este objeto con el valor `1`y `2` para la parte real e imaginaria, respectivamente.

Sin embargo, el segundo caso, aquel que se refiere al objeto `d`, es declarado sin ningún tipo de mensaje. En este caso, la declaración del objeto invocará al constructor por defecto, e inicializará el objeto con los valores `0` y `0`, para la parte real e imaginaria, respectivamente.


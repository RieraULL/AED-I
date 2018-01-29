# Objetos constantes

Ref. [code](https://github.com/RieraULL/AED-ULL/blob/master/code/code2.cpp)

Además de objetos variables, podemos definir objetos constantes a partir de otros objetos. El siguiente fragmento de código muestra una ejemplo.

```cpp
int main(void)
{
    complex_t a(1, 2);

    const complex_t aa(a), bb = a;

    cout << "Parte real      : "<< aa.get_real()   << endl;
    cout << "Parte imaginaria: "<< aa.get_imag()   << endl;
    cout << "Módulo          : "<< aa.get_modulo() << endl;
    cout << "Fase            : "<< aa.get_fase()   << endl;
    cout << endl;

    a.write_cartesian(cout);
    cout << endl;

    /* aa.set_real(5); ERROR */

    return 0;
}
```

Los objetos constantes, como el objeto `aa` no pueden ser modificados. Este tipo de objetos sólo puede invocar aquellos métodos de la clase que hayan sido declarados con el sufijo `const`. Declaramos este nuevo objeto utilizando un **constructor de copia**. El constructor de copia permite inicializar un objeto durante su declaración a partir de otro objeto existente. Normalmente no es neceesario declarar un constructor de copia. El compilador crea uno por defecto para cada tipo que definamos. Este constructor de copia transfiere el valor de los atributos del objeto emisor al objeto receptor. En nuestro caso, el objeto emisor sería el objeto `a`, que ha sido inicializado durante su declaración por el constructor con el mensaje `(1,2)`,  y el objeto receptor es el objeto constante `aa`.

Vemos entre comentarios una método que tiene como propósito actualizar el objeto constante `aa`.  ¿Qué sucede compilamos este fragmento de código deshabilitando los comentarios y eliminando la palabra `ERROR`?


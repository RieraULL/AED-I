# Declaración de referencias y referencias constantes

Ref. [code](https://github.com/RieraULL/AED-ULL/blob/master/code/code4.cpp)

Las *referencias* y *referencias constantes* son ingredientes del lenguaje C++ que permiten declarar alias de objetos. Las referencias permiten actuar sobre el objeto tal y como si fuera el objeto original, mientras que las referencias constantes no permiten la modificación del objeto.

```cpp
int main(void)
{
    complex_t a(1, 2);
    complex_t &ar(a), &br = a;
    const complex_t &cr = a;

    ar.write_cartesian(cout); cout << endl;

    ar.set_real(25);

    ar.write_cartesian(cout); cout << endl;

    br.set_real(2);
    a.write_cartesian(cout); cout << endl;

    return 0;
}
```

En este ejemplo definimos las referencias `ar` y `br` a partir del objeto `a`. También la referencia `cr` se declara a partir del objeto `a`, aunque en este caso es una referencia constante. Observa el contenido de las referencias y del objeto `a`a medida que avanza la ejecución del programa.


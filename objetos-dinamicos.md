# Objetos dinámicos

Ref. [code](https://github.com/RieraULL/AED-ULL/blob/master/code/code3.cpp)

En ocasiones debemos crear y destruir objetos de forma dinámica. En el siguiente ejemplo se declara cuatro punteros a objetos de tipo `complex_t`. El puntero `ap` se inicializa con la dirección del objeto `a`; el puntero `bp` se inicializa con la memoria reservada para un objeto dinámico que ha sido inicializado con el constructor al que se le pasa el mensaje `(6, 6)`; el puntero `cp` también se inicializa con un objeto dinámico creado a partir del constructor de copia inicializado con el objeto `b`, y finalmente, el puntero `dp` se inicializa con el puntero nulo.

```cpp
int main(void)
{
    complex_t a(1, 2), b(3, 4);

    complex_t *ap, *bp, *cp, *dp;

    ap = &a;
    bp = new complex_t(6, 7);
    cp = new complex_t(b);
    dp = NULL;

    cout << endl;
    ap->write_cartesian(cout); cout << endl;
    bp->write_cartesian(cout); cout << endl;
    cp->write_cartesian(cout); cout << endl;
    /* dp->write_cartesian(cout);  ERROR */
    cout << endl;

    ap = NULL;

    delete bp;
    bp = NULL;

    delete cp;
    cp = NULL;    

    return 0;
}
```

Téngase en cuenta que una vez que no se requiere el uso de alguna zona de memoria reservada dinámicamente, hay que proceder a su liberación. Así, la memoria apuntada dinámicamente por los puntero `bp` y `cp` debe ser liberada mediante `delete`. Por precaución, una vez que dejemos de utilizar un puntero, debemos asignarle el valor `NULL`.

Obsérvese que la invocación de un método desde un objeto dinámico o desde un puntero se lleva a cabo mediante los símbolos `->`, en lugar de `.`.


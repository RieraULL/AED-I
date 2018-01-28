# Invocando métodos

Para cambiar el estado de un objeto, o para acceder a su contenido debemos invocar el método adecuado. La invocación de un método por parte de un objeto se lleva a cabo llamando a dicho método precedido del nombre del objeto seguido de un punto, añadiendo el mensaje apropiado. A continuación se amplía el fragmento de código anterior incluyendo invocaciones a métodos.

```cpp
int main(void)
{
    complex_t a(1, 2), b;

    cout << endl;
    a.write_cartesian(cout);
    cout << endl;
    b.write_cartesian(cout);
    cout << endl;
    cout << endl;

    cout << "Parte real      : "<< a.get_real()   << endl;
    cout << "Parte imaginaria: "<< a.get_imag()   << endl;
    cout << endl;

    a.set_real(5);
    /* a.r_ = 5; ERROR */

    return 0;
}
```

Como se puede observar, los objetos `a` y `b` invocan al método `imprime_complejo` en el primer bloque de código con el mensaje `(cout)` \(un flujo de salida\) ¿Puedes adivinar qué se mostrará por pantalla?.

En el segundo bloque de código el objeto `a` invoca los métodos `get_real` y `get_imag`. ¿Qué aparecerá en pantalla?

Es importante comprender que los atributos de un objecto sólo pueden ser modificados a través del interfaz. En el fragmento de código vemos un ejemplo en el que se modifica la parte real del objeto `a` mediante el método `set_real`. La penúltima línea recoge un acceso erróneo al atributo `r_` del objeto `a`. ¿Sabrías por qué?

No obstante no todos los métodos se invocan a través de un objeto. Este es el caso de los métodos declarados bajo la claúsula `private`. Estos métodos sólo pueden ser invocados desde otro método perteneciente a la clase en que es definido. Suelen ser métodos auxiliares que sólo van a ser utilizados internamente.

A continuación se muestra un ejemplo en el que los métodos `get_mod`y `get_phase` han sido declarados bajo la claúsula `private`, y son utilizados de forma auxiliar por el procedimiento `write_polar`.

```cpp
void complex_t::write_polar(ostream& os) const
{
    const double mod = get_mod();
    const double pha = get_phase();

    os << setw(3) << fixed << setprecision(1) << mod;
    os << " cos(";
    os << setw(3) << fixed << setprecision(1) << pha;
    os << ") + ";
    os << setw(3) << fixed << setprecision(1) << mod;
    os << " i sin(";
    os << setw(3) << fixed << setprecision(1) << pha;
    os << ")";
}
```

Como se puede ver, ambos métodos privados son invocados directamente, sin estar precedidos por ningún objeto, ya que forman parte de la implementación de una clase.


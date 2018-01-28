# Implementando una clase

Ref. [code](code/code1.cpp)

Una vez hecha la declaración de los atributos y métodos, corresponde describir la **implementación de los métodos**, es decir, especificar qué operaciones lleva a cabo cada método. Esta implementación puede especificarse de diversas maneras. Una de ellas podría consistir en llevarla a cabo dentro de la propia declaración del método. Otra de las manera podría ser especificarla después de la definición de la clase, en un fichero aparte, o en el mismo fichero.

Veamos un ejemplo de este segundo caso.

```cpp
void complex_t::set_real(double r)
{
    r_=r;
}

void complex_t::set_imag(double i)
{
    i_=i;
}

double complex_t::get_real(void) const
{
    return r_;
}

double complex_t::get_imag(void) const
{
    return i_;
}
```

Cuando la implementación se especifica fuera de la propia clase la implementación de los métodos se lleva a cabo tal y como se suele especificar un procedimiento ordinario en lenguaje C, aunque el nombre del método debe ir precedido del nombre de la clase a la que pertenece, y separado por los símbolos `::`. En este ejemplo, los métodos `set_real` y `set_imag` modifican la parte real e imaginaria de un objeto declarado con el tipo `complex_t`, respectivamente.  Recuérdese que el sufijo `const` después del nombre del método hace referencia a que dicho método no modificará el contenido del objeto.

A continuación se muestra el fragmento de código correspondiente a la implementación de los dos constructores y del destructor.

```cpp
complex_t::complex_t(double r,double i)
{
    r_=r;
    i_=i;
}

complex_t::complex_t(void)
{
    r_=0;
    i_=0;
}

complex_t::~complex_t(void)
{
    cout << "-- Bye, bye, complex! --" << endl;
}
```

La implementación del primer constructor inicializa la parte real y la parte imaginaria de un objeto definido con el tipo `complex_t` con el mensaje pasado a través de los parámetros `r`e `i`, respectivamente. Sin embargo, el constructor por defecto, inicializa los atributos con el valor `0`.  Finalmente, el destructor muestra por pantalla un texto de despedida.


# Paso de parámetros por valor y por referencia

Ref. [code](https://github.com/RieraULL/AED-ULL/blob/master/code/code5.cpp)

El paso de objetos a alguna función o método se suele efectuar mediante una _referencia constante_ o una _referencia_ al objeto. En caso de que simplemente queramos pasar un objeto por _valor_, el cauce habitual es el uso de una referencia constante al parámetro. Esto se debe a que los objetos suelen ser estructuras complejas que pueden albergar gran cantidad de datos \(por ejemplo, una matriz\), así que, en caso de no utilizar una referencia constante, estaríamos enviando una copia completa de nuestro objeto al método que lo require. Sin embargo, si utilizamos una referencia constante, estaremos enviando únicamente la dirección que tiene dicho objeto en memoria, lo cual puede implicar una diferencia sustancial en memoria y eficiencia.

En caso de que deseemos alterar el contenido del parámetro dentro del método debemos pasarlo por referencia.

```cpp
class complex_t {
private:
    double r_;
    double i_;

public:

    complex_t(double r,double i);
    complex_t(void);

    ~complex_t(void);

    void write_cartesian(ostream& os) const;
    void write_polar(ostream& os) const;

    void set_real(double r);
    void set_imag(double i);

    double get_real(void) const;
    double get_imag(void) const;

    void get(complex_t& c) const;
    void set(const complex_t& c);

private:

    double get_mod(void) const;
    double get_phase(void) const;
};
```

```cpp
void complex_t::get(complex_t& c) const
{
    c.r_ = r_;
    c.i_ = i_;
}

void complex_t::set(const complex_t& c)
{
    r_ = c.r_;
    i_ = c.i_;
}
```


```cpp
int main(void)
{
    complex_t a(1, 2), b, c;

    b.set(a);
	b.get(c);

    b.write_cartesian(cout); cout << endl;
    c.write_cartesian(cout); cout << endl;

    return 0;
}
```




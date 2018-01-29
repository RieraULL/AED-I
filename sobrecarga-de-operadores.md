# Sobrecarga de operadores

Ref. [code](code/code6.cpp)

La sobrecarga de operadores extiende el mecanismo de la sobrecarga de funciones permitiendo definir operaciones involucrando operandos para los que la operación no estaba originalmente definida. Por ejemplo, el operador `+` está definido en C++ para operandos de tipo `int`,  `long`, `float`, `double`, ... Sin embargo, si intentamos efectuar una suma entre dos números complejos el compilador arrojará un mensaje de error. 

La sobrecarga de operadores permite redefinir los operadores. Veamos a continuación la redefinición de tres operadores para el caso del operador `<<`, salida a través de un *stream*, el operador `+` suma, y el operador `*`.

```cpp
ostream& operator<<(ostream& os, const complex_t& c)
{
	c.write_cartesian(os);
	return os;
}


complex_t operator+(const complex_t& c1, const complex_t& c2)  
{
	complex_t aux;

	aux.set_real(c1.get_real() + c2.get_real());
	aux.set_imag(c1.get_imag() + c2.get_imag());

	return aux;
}

complex_t operator*(const complex_t& c1,const complex_t& c2) 
{
	complex_t aux;

	aux.set_real(c1.get_real()*c2.get_real() - c1.get_imag()*c2.get_imag());
	aux.set_imag(c1.get_real()*c2.get_imag() + c2.get_real()*c1.get_imag());

	return aux;	
}
```
Obsérvese la sintaxis y ejecútese el código de referencia en un depurador para observar la ejecución paso a paso.

```cpp
int main(void)
{
	complex_t a(1, 2), b(2, 3), c(3, 4), d;

	c = a + b;
	d = a * b; 

	cout << c << endl;
	cout << d << endl;

	return 0;
}
```
**ACTIVIDAD**: ¿Serías capaz de sobrecargar el operador `+` para que efectúe la suma de un número complejo con uno real? ¿Serías capaz de sobrecargar el operador `+` para efectuar la suma entre un número real y un número complejo?

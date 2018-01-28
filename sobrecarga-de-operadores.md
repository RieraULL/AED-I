# Sobrecarga de operadores

Ref. [code](code/code6.cpp)

```
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

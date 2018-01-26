#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;


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

void complex_t::write_cartesian(ostream& os) const
{
	os << setw(3) << fixed << setprecision(1) << r_;
	os << " + ";
	os << setw(3) << fixed << setprecision(1) << i_;
	os << "i";
}

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

void complex_t::set_imag(double i)
{
	i_ = i;
}

double complex_t::get_real(void) const
{
	return r_;
}

double complex_t::get_imag(void) const
{
	return i_;
}

double complex_t::get_mod(void) const 
{
	return sqrt(r_ * r_ + i_* i_);	
}

double complex_t::get_phase(void) const
{
	return atan2(i_, r_);	
}

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


bool operator==(const complex_t& c1,const complex_t& c2)  
{
	return (c1.get_real() == c2.get_real()) && (c1.get_imag() == c2.get_imag());
}


int main(void)
{
	complex_t a(1, 2), b(2, 3), c(3, 4), d;

	cout << endl;
	a.write_cartesian(cout);
	cout << endl;
	b.write_cartesian(cout);
	cout << endl;
	c.write_cartesian(cout);
	cout << endl;
	d.write_cartesian(cout);
	cout << endl;
	cout << endl;

	cout << endl;
	a.write_polar(cout);
	cout << endl;
	b.write_polar(cout);
	cout << endl;
	c.write_polar(cout);
	cout << endl;
	d.write_polar(cout);
	cout << endl;
	cout << endl;

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << endl;
		
	cout << "Parte real      : "<< a.get_real()<< endl;
	cout << "Parte imaginaria: "<< a.get_imag()<< endl;

	cout << endl;


	const complex_t aa(a), bb = b, cc(c), dd(d);

	cout << endl;
	aa.write_cartesian(cout);
	cout << endl;
	bb.write_cartesian(cout);
	cout << endl;
	cc.write_cartesian(cout);
	cout << endl;
	dd.write_cartesian(cout);
	cout << endl;
	cout << endl;

	cout << "Parte real      : "<< aa.get_real()<< endl;
	cout << "Parte imaginaria: "<< aa.get_imag()<< endl;

	cout << endl;


	complex_t *ap, *bp, *cp, *dp;

	ap = &a;
	bp = new complex_t(6, 7);
	cp = new complex_t(bb);
	dp = NULL;

	cout << endl;
	ap->write_cartesian(cout);
	cout << endl;
	bp->write_cartesian(cout);
	cout << endl;
	cp->write_cartesian(cout);
	cout << endl;
	/* dp->write_cartesian(cout);  ERROR */
	cout << endl;

    ap = NULL;

	delete bp;
	bp = NULL;

	delete cp;
	cp = NULL;		


	complex_t &ar(a), &br = a;
	const complex_t &cr = a;

	cout << endl;
	ar.write_cartesian(cout);
	cout << endl;

	ar.set_real(25);

	ar.write_cartesian(cout);
	cout << endl;

	br.set_real(2);
	a.write_cartesian(cout);
	cout << endl;
	
	cr.write_cartesian(cout);
	cout << endl;	

	/* cr.set_real(5);  ERROR */

	cout << "Cambiando número: " << a; 
	a.set(c);
        //a.r_=5;               // ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!
	cout << " a "<< a << endl;
	cout << endl;

	cout << "Suma            : " << a << " + " << b<< " = ";

	c = a + b; 

	cout << c << endl;
	cout << endl;

	cout << "Producto        : "<< a << " * " << b << " = ";

	d = a * b;  

	cout << d << endl;
	cout << endl;

	return 0;
}


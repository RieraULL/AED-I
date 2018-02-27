/* Compilación: g++ -g rational.cpp -o rational */

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;


class rational_t {

private:

	int a_;
	int b_;

public:

	rational_t(int a, int b);

	~rational_t(void);
	
	ostream& write(ostream& os) const;

	void set_num(int a);
	void set_den(int b);
	
	double get_num(void) const;
	double get_den(void) const;

	void get(rational_t& c) const;
	void set(const rational_t& c);

	bool infinity(void) const;
	bool indeter(void) const;
	bool is_integer(void) const;
};
 
rational_t::rational_t(int a, int b)
{
	a_=a;
	b_=b;
}

rational_t::~rational_t(void)
{
	cout << "-- Bye, bye, rational! --" << endl;
}

ostream& rational_t::write(ostream& os) const
{
	os << setw(3) << a_;
	os << " /";
	os << setw(3) << b_;

	return os;
}

void rational_t::get(rational_t& r) const
{
	r.a_ = a_;
	r.b_ = b_;
}

void rational_t::set(const rational_t& r)
{
	a_ = r.a_;
	b_ = r.b_;
}

void rational_t::set_num(int a)
{
	a_ = a;
}

void rational_t::set_den(int b)
{
	b_ = b;
}

double rational_t::get_num(void) const
{
	return a_;
}

double rational_t::get_den(void) const
{
	return b_;
}

bool rational_t::infinity(void) const
{
	if ((a_ != 0) && (b_ == 0)) return true;
	else return false;
}

bool rational_t::indeter(void) const
{
	if ((a_ == 0) && (b_ == 0)) return true;
	else return false;
}

bool rational_t::is_integer(void) const
{
	if (a_ % b_ == 0) return true;
	else return false;
}

int main(void)
{
	rational_t a(1, 2), b(4, 2), c(1, 0), d(0, 0);

	a.write(cout); cout << endl;
	b.write(cout); cout << endl;
	c.write(cout); cout << endl;
	d.write(cout); cout << endl;
	cout << endl;
	a.write(cout); cout << " ¿Es infinito? " << a.infinity() << endl;
	b.write(cout); cout << " ¿Es infinito? " << b.infinity() << endl;
	c.write(cout); cout << " ¿Es infinito? " << c.infinity() << endl;
	d.write(cout); cout << " ¿Es infinito? " << d.infinity() << endl;
	cout << endl;
	a.write(cout); cout << " ¿Es indeterminado? " << a.indeter() << endl;
	b.write(cout); cout << " ¿Es indeterminado? " << b.indeter() << endl;
	c.write(cout); cout << " ¿Es indeterminado? " << c.indeter() << endl;
	d.write(cout); cout << " ¿Es indeterminado? " << d.indeter() << endl;
	cout << endl;
}


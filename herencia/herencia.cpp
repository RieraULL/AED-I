#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class position_t {
private:
	int x_;
	int y_;

public:
	position_t(int x, int y):
	x_(x),
	y_(y) {}

	~position_t(void) {}

	void set(int x, int y)
	{
		x_ = x;
		y_ = y;
	}

	int get_x(void) {return x_;}
	int get_t(void) {return y_;}

	void write(ostream& os) {os << "(" << x_ << ", " << y_ << ")";}
};

class shape_t: public position_t {

public:
	shape_t(const position_t& p):
	position_t(p) {}

	virtual ~shape_t(void) {}

	virtual double area(void) = 0;
	virtual double perimeter(void) = 0;
	virtual void write(ostream& os) = 0;
};


class trapecio_t: public shape_t 
{
private:
	double base_;
	double Base_;
	double h_;

public:
	trapecio_t(const position_t& p, double base, double Base, double h):
	shape_t(p),
	base_(base),
	Base_(Base),
	h_(h) {} 

	virtual ~trapecio_t(void) {}

	virtual double area(void) {return (Base_ + base_) * h_ * 0.5;}

	virtual double perimeter(void) {Base_ + base_ + 2 * sqrt(h_ * h_ + (Base_ - base_) * (Base_ - base_) * 0.25);}

	virtual void write(ostream& os) 
	{
		os << "Trapecio en posición: ";
		position_t::write(os);
	}	
};

class triangle_t: public trapecio_t
{
public:
	triangle_t(const position_t& p, double Base, double h):
	trapecio_t(p, 0, Base, h) {}

	virtual ~triangle_t(void) {}

	virtual void write(ostream& os) 
	{
		os << "Triángulo en posición: ";
		position_t::write(os);
	}
};

class rectangle_t: public trapecio_t
{
public:
	rectangle_t(const position_t& p, double Base, double h):
	trapecio_t(p, 0, Base, h) {}

	virtual ~rectangle_t(void) {}

	virtual void write(ostream& os) 
	{
		os << "Rectángulo en posición: ";
		position_t::write(os);
	}
};

class square_t: public rectangle_t
{
public:
	square_t(const position_t& p, double base):
	rectangle_t(p, base, base) {}

	virtual ~square_t(void) {};

	virtual void write(ostream& os) 
	{
		os << "Cuadrado en posición: ";
		position_t::write(os);
	}
};


int main(void)
{
	vector<shape_t*> formas(4);

	formas[0] = new square_t(position_t(1,1), 5);
	formas[1] = new rectangle_t(position_t(3,2), 4, 3);
	formas[2] = new triangle_t(position_t(4,6), 2, 1);
	formas[3] = new trapecio_t(position_t(1,1), 5, 4, 3);

	for(int i = 0; i < 4; i ++)
	{
		formas[i]->write(cout); cout << endl;
		cout << "Area     : " << formas[i]->area() << endl;
		cout << "Perímetro: " << formas[i]->perimeter() << endl;
	}


	return 0;
}

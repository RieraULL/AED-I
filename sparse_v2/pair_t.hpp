#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

template <class T >
class pair_t
{
private:
	int    inx_;
	T      val_;
public:
	pair_t(void):
		inx_(-1),
		val_(){} 

	pair_t(int inx, T val):
		inx_(inx),
		val_(val){}

	~pair_t(void) {}

	void set(int inx, T val){
	
		inx_ = inx;
		val_ = val;
	}

	int    get_inx(void) const {return inx_;}
	T      get_val(void) const {return val_;}

	ostream& write(ostream& os) const {
	
		os << setw(7) << inx_ << " " << setw(5) << val_;
		return os;
	}

	istream& read(istream& is){
	
		is >> inx_ >> val_;
		return is;
	}
};

template<>
ostream& pair_t<double>::write(ostream& os) const {

	os << setw(7) << inx_ << " " << setw(5)<< fixed << setprecision(1) << val_;
	return os;
}

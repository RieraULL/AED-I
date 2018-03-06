#pragma once

#include "pair_t.hpp"
#include "vector_t.hpp"
#include <cstdio>

#include <iostream>
#include <iomanip>

#include <cassert>

using namespace std;


typedef vector_t<pair_t<double> > vector_pair_t ;



template <>
ostream& vector_t<pair_t<double> >::write(ostream& os) const{

	os <<  sz_ << endl;

	for(int i = 0; i < sz_; i ++){
		v_[i].write(os);
		os << endl;
	}

	return os;
}

template <>
istream& vector_t<pair_t<double> >::read(istream& is){
	
	is >> sz_;

	resize(sz_);

	for(int i = 0; i < sz_; i ++)
	 	v_[i].read(is);

	return is;
}

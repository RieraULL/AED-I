#pragma once

#include "pair_t.hpp"
#include <cstdio>

#include <iostream>
#include <iomanip>

#include <cassert>

using namespace std;

class vector_pair_t{
private:
	pair_t* v_;
	int     sz_;

public:

	vector_pair_t(void):
		v_(NULL),
		sz_(0) {}

	vector_pair_t(int sz):
		v_(NULL),
		sz_(sz) {

		crea_vector();
	}

	~vector_pair_t(void){

		destruye_vector();
	}

	void resize(int sz)
	{
		destruye_vector();
		sz_ = sz;
		crea_vector();
	}

	int get_sz(void) const
	{
		return sz_;
	}

	pair_t get_v(int pos) const{

		assert((pos < sz_) && ((pos >= 0)));

		return v_[pos];
	}

	pair_t& get_set_v(int pos){

		assert((pos < sz_) && ((pos >= 0)));

		return v_[pos];
	}

	ostream& write(ostream& os) const{
	
		for(int i = 0; i < sz_; i ++){
		 	v_[i].write(os);
			os << " ";
		}

		return os;
	}

	istream& read(istream& is){
	
		is >> sz_;

		resize(sz_);

		for(int i = 0; i < sz_; i ++)
		 	v_[i].read(is);

		return is;
	}

private:

	void crea_vector(void){
		v_ = new pair_t[sz_];
	}

	void destruye_vector(void)
	{
		if (v_ != NULL){
			delete [] v_;
			v_ = NULL;
		}
	}

};

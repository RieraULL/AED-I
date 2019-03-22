#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>

#include <cassert>

using namespace std;

namespace AyED {

template <class T>
class vector{
private:
	T*      v_;
	int     sz_;

public:

	vector(void):
		v_(NULL),
		sz_(0) {}

	vector(int sz):
		v_(NULL),
		sz_(sz) {

		crea_vector();
	}
	
	vector(const vector& v):
	v_(NULL),
	sz_(v.sz_)
	{
		crea_vector();
		
	    for(int i = 0; i < sz_; i++)
	        v_[i] = v.v_[i];
	}
	
	vector& operator=(const vector& v)
	{
	    resize(v.sz_);
	    
	    for(int i = 0; i < sz_; i++)
	        v_[i] = v.v_[i];
	        
	     return *this;
	}
	
	~vector(void){

		destruye_vector();
	}

	void resize(int sz)
	{
		destruye_vector();
		sz_ = sz;
		crea_vector();
	}

	int size(void) const
	{
		return sz_;
	}

	const T& at(int pos) const{
		
		assert((pos < sz_) && ((pos >= 0)));

		return v_[pos];
	}

	T& at(int pos){

		assert((pos < sz_) && ((pos >= 0)));

		return v_[pos];
	}
	
	const T& operator[](int pos) const {
		return at(pos);
	}
	
	T& operator[](int pos) {
		return at(pos);
	}

private:

	void crea_vector(void){
		v_ = new T[sz_];
	}

	void destruye_vector(void)
	{
		if (v_ != NULL){
			delete [] v_;
			v_ = NULL;
		}
	}

};
}
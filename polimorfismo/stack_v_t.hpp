#pragma once

#include "stack_t.hpp"
#include <vector>
#include <iomanip>

#define MAX_STACK_SIZE 20

using namespace std;

template <class T>
class stack_v_t: public stack_t<T> {
private:
	vector<T> v_;
	int       top_;

public:	
	stack_v_t(void):
	stack_t<T> (),
	v_(MAX_STACK_SIZE),
	top_(-1) {}

	virtual ~stack_v_t(void) {}

	virtual bool empty(void) const{
		return (top_ < 0);
	}

	virtual T _top(void) const{
		return v_[top_];
	}

	virtual void _pop(void){

		top_--;
	}

	virtual void _push(T dato){

		top_ ++;
		v_[top_] = dato;
	}

protected:
	virtual bool full(void) const
	{
		return (top_ >= MAX_STACK_SIZE - 1);
	}

};


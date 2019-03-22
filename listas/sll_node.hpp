#pragma once

#include <iostream>
using namespace std;

#define NULL_PTR -1

namespace AyED {

	template <class T>
	class sll_node {
	private:
		int  next_;
		T    data_;

	public:
		sll_node(void);
		sll_node(const T& data);
		~sll_node(void);

		void set_next(int next);
		int get_next(void) const;

		void set_data(const T& data);
		const T& get_data(void) const;

		ostream& write(ostream& os) const;
	};

	template <class T>
	sll_node<T>::sll_node():
	data_(),
	next_(NULL_PTR)
	{}

	template <class T>
	sll_node<T>::sll_node(const T& data) :
	data_(data),
	next_(NULL_PTR)
	{}

	template <class T>
	sll_node<T>::~sll_node(void) 
	{
		next_ = NULL_PTR;
	}

	template <class T>
	void sll_node<T>::set_next(int next)
	{
		next_ = next;
	}

	template <class T>
	int sll_node<T>::get_next(void) const
	{
		return next_;
	}

	template <class T>
	void sll_node<T>::set_data(const T& data)
	{
		data_ = data;
	}

	template <class T>
	T sll_node<T>::get_data(void) const
	{
		return data_;
	}

	template <class T>
	ostream& sll_node<T>::write(ostream& os) const
	{
		os << data_;
		return os;
	}
}

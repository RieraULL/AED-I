#pragma once

#include <iostream>
using namespace std;

namespace AED {

	template <class T>
	class sll_node_t {
	private:
		sll_node_t<T>* next_;
		T              data_;

	public:
		sll_node_t(void);
		sll_node_t(T data);
		~sll_node_t(void);

		void set_next(sll_node_t<T>* next);
		sll_node_t<T>* get_next(void) const;

		void set_data(const T& data);
		T get_data(void) const;

		ostream& write(ostream& os) const;
	};

	template <class T>
	sll_node_t<T>::sll_node_t():
	data_(),
	next_(NULL)
	{}

	template <class T>
	sll_node_t<T>::sll_node_t(T data) :
	data_(data),
	next_(NULL)
	{}

	template <class T>
	sll_node_t<T>::~sll_node_t(void) 
	{
		next_ = NULL;
	}

	template <class T>
	void sll_node_t<T>::set_next(sll_node_t<T>* next)
	{
		next_ = next;
	}

	template <class T>
	sll_node_t<T>* sll_node_t<T>::get_next(void) const
	{
		return next_;
	}

	template <class T>
	void sll_node_t<T>::set_data(const T& data)
	{
		data_ = data;
	}

	template <class T>
	T sll_node_t<T>::get_data(void) const
	{
		return data_;
	}

	template <class T>
	ostream& sll_node_t<T>::write(ostream& os) const
	{
		os << data_;
		return os;
	}
}

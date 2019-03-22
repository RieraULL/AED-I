#pragma once

#include <iostream>
using namespace std;

#define NULL_PTR -1

namespace AyED {

	template <class T>
	class sll_node_t {
	private:
		int next_;
		T   data_;

	public:
		sll_node_t(void);
		sll_node_t(const T& data);
		~sll_node_t(void);

		void set_next(int next);
		int get_next(void) const;

		void set_data(const T& data);
		const T& get_data(void) const;

		ostream& write(ostream& os) const;
	};

	template <class T>
	sll_node_t<T>::sll_node_t():
	data_(),
	next_(NULL_PTR)
	{}

	template <class T>
	sll_node_t<T>::sll_node_t(const T& data) :
	data_(data),
	next_(NULL_PTR)
	{}

	template <class T>
	sll_node_t<T>::~sll_node_t(void) 
	{}

	template <class T>
	void sll_node_t<T>::set_next(int next)
	{
		next_ = next;
	}

	template <class T>
	int sll_node_t<T>::get_next(void) const
	{
		return next_;
	}

	template <class T>
	void sll_node_t<T>::set_data(const T& data)
	{
		data_ = data;
	}

	template <class T>
	const T& sll_node_t<T>::get_data(void) const
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

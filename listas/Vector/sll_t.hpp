#pragma once

#include <iostream>
using namespace std;

#include "sll_node_t.hpp"
#include "memory_t.hpp"

namespace AyED {

   	template <class T>
	class sll_t {
	private:
		int head_;
		memory_t<T>& memory_;

	public:
		sll_t(memory_t<T>& memory);
		virtual ~sll_t(void);

		void insert_head(int n);
		int extract_head(void);

		void insert_after(int pred, int n);
		int extract_after(int pred);

		bool empty(void) const;	
		ostream&  write(ostream& os) const;
		
		int search(const T& d) const;
	};

	template <class T>
	sll_t<T>::sll_t(memory_t<T>& memory) :
	head_(NULL_PTR),
	memory_(memory) {}

	template <class T>
	sll_t<T>::~sll_t(void) {}

	template <class T>
	bool sll_t<T>::empty(void) const {
		return (head_ == NULL_PTR);
	}

	template <class T>
	void sll_t<T>::insert_head(int n)
	{
		memory_[n].set_next(head_);
		head_ = n;
	}

	template <class T>
	int sll_t<T>::extract_head(void) {

		int aux = head_;
		head_ = memory_[head_].get_next();
		memory_[aux].set_next(NULL_PTR);

		return aux;
	}

	template <class T>
	void sll_t<T>::insert_after(int prev, int n)
	{
		memory_[n].set_next(memory_[prev].get_next());
		memory_[prev].set_next(n);
	}

	template <class T>
	int sll_t<T>::extract_after(int prev) {

		int aux = memory_[prev].get_next();
		memory_[prev].set_next(memory_[aux].get_next());
		memory_[aux].set_next(NULL_PTR);

		return aux;
	}

	template <class T>
	ostream& sll_t<T>::write(ostream& os) const {
	
		int aux = head_;

		while (aux != NULL_PTR) {
		    memory_[aux].write(os);
		    aux = memory_[aux].get_next();
		}
	}
	
	template <class T>
    int sll_t<T>::search(const T& d) const
	{
		int aux = head_;
		
		while((aux != NULL_PTR) && (memory_[aux].get_data() != d))
			aux = memory_[aux].get_next();
			
		return aux;
	}
    
}

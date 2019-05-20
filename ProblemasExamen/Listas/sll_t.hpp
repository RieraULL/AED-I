#pragma once

#include <stack>

#include <iostream>
using namespace std;

#include "sll_node_t.hpp"

namespace AED {

   	template <class T>
	class sll_t {
	private:
		sll_node_t<T>* head_;

	public:
		sll_t(void);
		virtual ~sll_t(void);

		void insert_head(sll_node_t<T>* n);
		sll_node_t<T>* extract_head(void);

		void insert_after(sll_node_t<T>* pred, sll_node_t<T>* n);
		sll_node_t<T>* extract_after(sll_node_t<T>* pred);

		bool empty(void) const;	
		void write(ostream& os) const;
		
		sll_node_t<T>* search(const T& d) const;
		
		// Impleméntese dos procedimientos, uno de ellos recursivo, para imprimir 
		// el contenido de una lista enlazada de enteros, de acuerdo con la descripción 
		// de clase dadas anteriormente.
		void writeReverse(ostream& os) const;
		void write1(sll_node_t<T>* node, ostream& os) const;
		
		// Impleméntese dos procedimientos, uno de ellos recursivo, para imprimir
		// el contenido de una lista enlazada de enteros, de acuerdo con la descripción 
		// de clases dada anteriormente.
		void writeDirect(ostream& os) const;
		void write2(sll_node_t<T>* node, ostream& os) const;
		
		// Impleméntese un procedimiento iterativo para imprimir al revés el contenido 
		// de una lista enlazada de enteros, utilizando una pila auxiliar, de acuerdo 
		// con la descripción de clases dada anteriormente.
		void writeReverseStack(ostream& os) const;
	};
	
	template <class T>
	void sll_t<T>::writeReverse(ostream& os) const
	{ 
		write1(head_, os);
	}	
	
	template <class T>
	void sll_t<T>::write1(sll_node_t<T>* node, ostream& os) const
	{ 
	   if(node != NULL){
	    	write1(node->get_next(), os);
	    	os << node->get_data();
		}
	}	
	
	template <class T>
	void sll_t<T>::writeDirect(ostream& os) const
	{ 
		write2(head_, os);
	}	
	
	template <class T>
	void sll_t<T>::write2(sll_node_t<T>* node, ostream& os) const
	{ 
		if(node != NULL){
	    	os << node->get_data(); 
			write2(node->get_next(), os);
	  }
	}	

	template <class T>
	void sll_t<T>::writeReverseStack(ostream& os) const
	{ 
		stack<T> stack;
		sll_node_t<T>* aux = head_;
		
		while (aux != NULL) {
	    	stack.push(aux->get_data());
	    	aux = aux->get_next();
		}
	
		while(!stack.empty()) {
	    	os << stack.top();
	    	stack.pop();
		}
	}

	template <class T>
	sll_t<T>::sll_t(void) :
	head_(NULL){}

	template <class T>
	sll_t<T>::~sll_t(void) {

		while (!empty()) {
		    
		    sll_node_t<T>* aux = head_;
		    head_ = head_->get_next();
		    delete aux;
		}
	}

	template <class T>
	bool sll_t<T>::empty(void) const {
		return (head_ == NULL);
	}

	template <class T>
	void sll_t<T>::insert_head(sll_node_t<T>* n)
	{
		n->set_next(head_);
		head_ = n;
	}

	template <class T>
	sll_node_t<T>* sll_t<T>::extract_head(void) {

		sll_node_t<T>* aux = head_;
		head_ = head_->get_next();
		aux->set_next(NULL);

		return aux;
	}

	template <class T>
	void sll_t<T>::insert_after(sll_node_t<T>* prev, sll_node_t<T>* n)
	{
		n->set_next(prev->get_next());
		prev->set_next(n);
	}

	template <class T>
	sll_node_t<T>* sll_t<T>::extract_after(sll_node_t<T>* prev) {

		sll_node_t<T>* aux = prev->get_next();
		prev->set_next(aux->get_next());
		aux->set_next(NULL);

		return aux;
	}

	template <class T>
	void sll_t<T>::write(ostream& os) const {
	
		sll_node_t<T>* aux = head_;

		while (aux != NULL) {
		    aux->write(os);
		    aux = aux->get_next();
		}
	}
	
	template <class T>
	sll_node_t<T>* sll_t<T>::search(const T& d) const
	{
		sll_node_t<T>* aux = head_;
		
		while((aux != NULL) && (aux->get_data() != d))
			aux = aux->get_next();
			
		return aux;
	}
    
}

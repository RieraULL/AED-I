#pragma once

#include <iostream>
#include <stack>
using namespace std;

#include "sll_node_t.hpp"

namespace AED
{

template <class T>
class sll_t
{
private:
      sll_node_t<T>* head_;

public:
      sll_t(void);
      virtual ~sll_t(void);

      void insert_head(sll_node_t<T>* n);
      sll_node_t<T>* extract_head(void);

      void insert_after(sll_node_t<T>* pred, sll_node_t<T>* n);
      sll_node_t<T>* extract_after(sll_node_t<T>* pred);

      sll_node_t<T>* head(void);

      bool empty(void) const;
      void write(ostream& os) const;
      void inverse_write(ostream& os) const;

      sll_node_t<T>* tail(void);

      void insert_tail(sll_node_t<T>* n);

      sll_node_t<T>* extract_tail(void);

      void invPar(const sll_t<T>& L)
      {
            invPar(L.head_);
      }
      
      void invPar(const sll_node_t<T>* n)
      {
            if (n != NULL){
                  const T& n_d = n->get_data();
                  if (n_d % 2 != 0)
                        insert_head(new sll_node_t<T>(n_d));
                        
                  invPar(n->get_next());
            }
      }

      void merge1(sll_t<T>& L1, sll_t<T>& L2)
      {
            sll_node_t<T>* L1_h = L1.head_;
            sll_node_t<T>* L2_h = L2.head_;
            
            stack<sll_node_t<T>*> pila;

            while ((L1_h != NULL) && (L2_h != NULL)) {
                  
                  const T& L1_d = L1_h->get_data();
                  const T& L2_d = L2_h->get_data();

                  if (L1_d < L2_d) {
                        L1_h = L1_h->get_next();
                        sll_node_t<T>* L1_a = L1.extract_head();
                        pila.push(L1_a);
                  } else {
                        L2_h = L2_h->get_next();
                        sll_node_t<T>* L2_a = L2.extract_head();
                        pila.push(L2_a);
                  }
            }

            while (L1_h != NULL) {
                  L1_h = L1_h->get_next();
                  sll_node_t<T>* L1_a = L1.extract_head();
                  pila.push(L1_a);
            }
            
            while (L2_h != NULL) {
                  L2_h = L2_h->get_next();
                  sll_node_t<T>* L2_a = L2.extract_head();
                  pila.push(L2_a);
            }       

            while (!pila.empty())
            {
                 sll_node_t<T>* aux = pila.top();
                 pila.pop();
                 insert_head(aux);
            }
      }
      
      void merge2(const sll_t<T>& L1, const sll_t<T>& L2)
      {
            sll_node_t<T>* L1_h = L1.head_;
            sll_node_t<T>* L2_h = L2.head_;

            while ((L1_h != NULL) && (L2_h != NULL)) {
                  
                  const T& L1_d = L1_h->get_data();
                  const T& L2_d = L2_h->get_data();

                  if (L1_d > L2_d) {
                        insert_head(new sll_node_t<T>(L1_d));
                        L1_h = L1_h->get_next();
                  } else {
                        insert_head(new sll_node_t<T>(L2_d));
                        L2_h = L2_h->get_next();
                  }
            }

            while (L1_h != NULL) {
                  insert_head(new sll_node_t<T>(L1_h->get_data()));
                  L1_h = L1_h->get_next();
            }
            
            while (L2_h != NULL) {
                  insert_head(new sll_node_t<T>(L2_h->get_data()));
                  L2_h = L2_h->get_next();
            }       
      }      

private:

      void write_reverse(ostream& os, sll_node_t<T>* n);
};

template <class T>
sll_t<T>::sll_t(void) :
      head_(NULL) {}

template <class T>
sll_t<T>::~sll_t(void)
{

      while (!empty()) {

            sll_node_t<T>* aux = head_;
            head_ = head_->get_next();
            delete aux;
      }
}

template <class T>
bool sll_t<T>::empty(void) const
{
      return (head_ == NULL);
}

template <class T>
void sll_t<T>::insert_tail(sll_node_t<T>* n)
{
      sll_node_t<T>* prev = tail();

      if (prev == NULL)
            insert_head(n);
      else
            insert_after(prev, n);
}

template <class T>
sll_node_t<T>* sll_t<T>::tail(void)
{
      if (empty())
            return NULL;
      else {

            sll_node_t<T>* aux = head_;

            while (aux->get_next() != NULL)
                  aux = aux->get_next();

            return aux;
      }
}

template <class T>
sll_node_t<T>* sll_t<T>::extract_tail(void)
{
      assert(!empty());

      if (head_->get_next() == NULL)
            return extract_head();

      else {
            sll_node_t<T>* aux = head_;

            while (aux->get_next()->get_next() != NULL)
                  aux = aux->get_next();

            return extract_after(aux);
      }
}

template <class T>
void sll_t<T>::insert_head(sll_node_t<T>* n)
{
      n->set_next(head_);
      head_ = n;
}

template <class T>
sll_node_t<T>* sll_t<T>::extract_head(void)
{

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
sll_node_t<T>* sll_t<T>::head(void)
{
      return head_;
}

template <class T>
sll_node_t<T>* sll_t<T>::extract_after(sll_node_t<T>* prev)
{
      sll_node_t<T>* aux = prev->get_next();
      prev->set_next(aux->get_next());
      aux->set_next(NULL);

      return aux;
}

template <class T>
void sll_t<T>::write(ostream& os) const
{
      sll_node_t<T>* aux = head_;

      while (aux != NULL) {
            aux->write(os);
            aux = aux->get_next();
      }
}

template <class T>
void sll_t<T>::inverse_write(ostream& os) const
{
      write_reverse(head_);
}

template <class T>
void sll_t<T>::write_reverse(ostream& os, sll_node_t<T>* n)
{
      if (n != NULL)
            write_reverse(os, n->get_next());
      else
            os << n->get_data() << " ";
}


}

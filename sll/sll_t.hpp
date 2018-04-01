#pragma once

#include <iostream>
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
            insert_after(prev);
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

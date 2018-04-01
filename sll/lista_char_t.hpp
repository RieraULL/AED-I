#pragma once

#include <iostream>
using namespace std;

#include "sll_t.hpp"

class lista_char_t
{
private:

      AED::sll_t<char> list_;

public:
      lista_char_t(void):
            list_() {}

      ~lista_char_t(void) {}

      bool empty(void)
      {
            return list_.empty();
      }

      void write(ostream& os)
      {
            list_.write(os);
      }

      void insert_head(char c)
      {
            AED::sll_node_t<char>* n = new AED::sll_node_t<char>(c);
            list_.insert_head(n);
      }

      char extract_head()
      {
            AED::sll_node_t<char>* n = list_.extract_head();
            char c = n->get_data();
            delete n;

            return c;
      }
};

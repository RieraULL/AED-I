#pragma once

#include <cstdio>
#include <iostream>
#include "matrix.hpp"
#include "color.hpp"
#include "point.hpp"

using namespace std;



namespace AEDA
{

class grid: protected matrix<color_t>
{
public:
      grid(size_t m, size_t n):
            matrix<color_t>(m, n)
      {
            init();
      }

      virtual ~grid(void) {}

/*      bool is_SB(const point& p)
      {
            return ((p.get_row() == 1) || (p.get_col() == 1) || (p.get_row() == matrix<unsigned short>::get_m()) || (p.get_col() == matrix<unsigned short>::get_n()));
      } */

      void resize(size_t m, size_t n)
      {
            matrix<color_t>::resize(m, n);
      }

      void change_color(const point& p)
      {
            matrix<color_t>::at(p.get_row(), p.get_col()) = (matrix<color_t>::at(p.get_row(), p.get_col()) + 1) % NCOLORS;
      }
      
      color_t get_color(const point& p){
          
          return matrix<color_t>::at(p.get_row(), p.get_col());
          
      }

protected:
      virtual void init(void)
      {
            for(size_t i = 1; i <= matrix<color_t>::get_m(); i++)
                  for(size_t j = 1; j <= matrix<color_t>::get_n(); j++)
                        matrix<unsigned short>::at(i,j) = WHITE;
      }
};

}

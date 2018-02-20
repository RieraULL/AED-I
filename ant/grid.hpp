#pragma once

#include <cstdio>
#include <iostream>
#include "matrix.hpp"
#include "ant.hpp"

using namespace std;

namespace AEDA {
    
    enum Background {BLACK, WHITE};

    const char Background_char[] = {'X', ' '};
    
    class grid: public matrix<unsigned short>
    {
      public:
        grid(size_t m, size_t n):
        matrix<unsigned short>(m, n) {
            
            for(size_t i = 1; i <= m; i++)
                for(size_t j = 1; j <= n; j++)
                    matrix<unsigned short>::get(i,j) = WHITE;
        }
        
        ~grid(void) {}
        
        void set_BLACK(size_t i, size_t j) {matrix<unsigned short>::get(i,j) = BLACK;}
        
        void set_WHITE(size_t i, size_t j) {matrix<unsigned short>::get(i,j) = WHITE;}
        
        void change_color(size_t i, size_t j) {matrix<unsigned short>::get(i,j) = (matrix<unsigned short>::get(i,j) + 1) % 2;}
        
        void write(ostream& os, const ant& a) const {
        
             for(size_t i = 1; i <= matrix<unsigned short>::get_m(); i++){
                 
                for(size_t j = 1; j <= matrix<unsigned short>::get_n(); j++)
                    if (((size_t)(a.get_x()) == i) && ((size_t)(a.get_y()) == j))
                        os << a;
                    else
                        os << Background_char[matrix<unsigned short>::get(i,j)];          
                    
                os << endl;
             } 
            
        }        
    };
    
}

#pragma once

#include <cstdio>

#include "ant.hpp"
#include "grid.hpp"
#include "config.hpp"

using namespace std;

namespace AEDA {
    
    class machine {
      
    private:
            ant           ant_;
            grid          grid_;

            const size_t  max_iter_;
            size_t        curr_iter_; 
            
    public:
        machine(const config& conf):
        ant_(conf.initial_position_, conf.initial_direction_),
        grid_(conf.rows_, conf.cols_),
        max_iter_(conf.max_iterations_),
        curr_iter_(0)
        {}
        
        ~machine(void) {}
        
      void write(ostream& os, const ant& a) const {
        
         /*    for(size_t i = 1; i <= matrix<unsigned short>::get_m(); i++){
                 
                for(size_t j = 1; j <= matrix<unsigned short>::get_n(); j++)
                    if (((size_t)(a.get_row()) == i) && ((size_t)(a.get_col()) == j))
                        a.write(os);
                    else
                        os << Background_char[matrix<unsigned short>::get(i,j)];          
                    
                os << endl;
             } */ 
        }      
        
    };
}
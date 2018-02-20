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
        
        
        
    };
}
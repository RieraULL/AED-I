#pragma once

#include <cstdio>

#include "point.hpp"

using namespace std;

namespace AEDA {
    
    class config {
      
    public:
        point           initial_position_;
        unsigned short  initial_direction_;
        
        size_t          rows_;
        size_t          cols_;
        
        
        
        size_t          max_iterations_;
        
    };
    
}
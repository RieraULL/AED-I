#pragma once
#include <cstdio>

using namespace std;

namespace AEDA {
 
    class point {
        
    private:
        
        size_t x_;
        size_t y_;
        
    public:
    
        point(void):
        x_(1),
        y_(1) {}
        
        point(size_t x, size_t y):
        x_(x),
        y_(y) {}
        
        ~point(void) {}
        
        size_t get_x(void) const {return x_;}
        size_t get_y(void) const {return y_;}
        
        void set(size_t x, size_t y) {x_ = x; y_ = y;}        
    };
   
}

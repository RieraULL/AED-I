#pragma once

namespace AEDA {
 
    class point {
        
    private:
        
        int x_;
        int y_;
        
    public:
    
        point(void):
        x_(0),
        y_(0) {}
        
        point(int x, int y):
        x_(x),
        y_(y) {}
        
        ~point(void) {}
        
        int get_x(void) const {return x_;}
        int get_y(void) const {return x_;}
        
        void set(int x, int y) {x_ = x; y_ = y;}        
    };
   
}
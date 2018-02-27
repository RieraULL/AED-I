#pragma once
#include <cstdio>

using namespace std;

namespace AEDA {
 
    class point {
        
    private:
        
        size_t row_;
        size_t col_;
        
    public:
    
        point(void):
        row_(1),
        col_(1) {}
        
        point(size_t row, size_t col):
        row_(row),
        col_(col) {}
        
        ~point(void) {}
        
        size_t get_row(void) const {return row_;}
        size_t get_col(void) const {return col_;}
        
        void set(size_t row, size_t col) {row_ = row; col_ = col;}        
        void add(const point& p) {row_ += p.row_; col_ += p.col_;}
    };
   
}

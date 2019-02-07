#pragma once 

#include <vector>
#include <iostream>

using namespace std;


namespace CyA
{

class sorted_vector_t: public vector<int>
{
public:
    sorted_vector_t(void):
    vector<int>() {}
    
    sorted_vector_t(const vector<int>& v):
    vector<int>(v) {}
    
    ~sorted_vector_t(void) {}
    
    void merge_sort(void);
    
    void write(ostream& os) const;    
    
private:
        
    void create_vector_sentinel(int l, int r, vector<int>& v);
    void merge(const vector<int>& v1, const vector<int>& v2, int l);
    
    void merge_sort(int l, int r);
    void merge(int l, int c, int d);
};

}

ostream& operator<<(ostream& os, const CyA::sorted_vector_t& v);
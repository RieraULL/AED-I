/* Compilar: g++ -g main.cpp vector_t.cpp -o vector */

#include <iostream>
#include <iomanip>

using namespace std;

#include "vector_t.hpp"

#define VECTOR_SZ 10

int main(void)
{
    const int sz = VECTOR_SZ;
    
    vector_t v(sz);
    vector_t w;
    
    w.resize(sz);
    
    double val = 5.0;

    for(int i = 0; i < sz; i++){
        
        v.at(i) = val;
        
        val += 0.05;
        
        w[i] = val;
    }
    
    v.write(cout); cout << endl;
    cout << w << endl;
}

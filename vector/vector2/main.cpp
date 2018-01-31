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

    const int ocur1 = v.ocurrencias(5.2, 0.001);
    const int ocur2 = v.ocurrencias(5.2, 0.100);
    const int ocur3 = v.ocurrencias(5.2, 0.500);
    
    cout << setw(5) << ocur1 << setw(5) << ocur2 << setw(5) << ocur3 << endl;
    
    cout << v * w << endl;
    cout << v.scalprod(w) << endl;
}

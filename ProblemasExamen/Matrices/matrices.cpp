#include <iostream>
#include "matrix_t.hpp"

using namespace std;

int main(void)
{
    matrix_t<double> A(3,3);
    
    A(1,1) =  3;
    A(1,2) =  2;
    A(1,3) = -3;
    A(2,1) =  7;
    A(2,2) = -1;
    A(2,3) =  0;
    A(3,1) =  2;
    A(3,2) = -4;
    A(3,3) =  5;

    A.write(cout);
    cout << endl;
    
    matrix_t<double> M;
    
    A.N_D(M);
    M.write(cout);
    cout << endl;
    
    A.N_ND(M);
    M.write(cout);
    cout << endl;   
    
    A.S_D(M);
    M.write(cout);
    cout << endl;
    
    A.S_ND(M);
    M.write(cout);
    cout << endl; 
    
    A.W_D(M);
    M.write(cout);
    cout << endl;
    
    A.W_ND(M);
    M.write(cout);
    cout << endl;   
    
    A.E_D(M);
    M.write(cout);
    cout << endl;
    
    A.E_ND(M);
    M.write(cout);
    cout << endl;    
    
    A.TSD(M);
    M.write(cout);
    cout << endl;  
    
    A.TSND(M);
    M.write(cout);
    cout << endl; 
    
    A.TID(M);
    M.write(cout);
    cout << endl;  
    
    A.TIND(M);
    M.write(cout);
    cout << endl;      
    
    const double Det = A.determinante();
    
    cout << "Determinante: " << Det << endl;
    
    return 0;
}

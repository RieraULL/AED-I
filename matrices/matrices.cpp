// Compila: g++ -g -o matrices matrices.cpp

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cassert>

#define MAX_VAL 2

using namespace std;

class  vector_t {
    private:
        int * v_;
        int   sz_;
        
    public:
        vector_t(int sz):
        v_(NULL),
        sz_(sz)
        {
            build();
        }
        
        ~vector_t(void)
        {
            destroy();
        }
        
        int get_sz(void) const
        {
            return sz_;
        }
        
        int& at(int i)
        {
            return v_[i];
        }
        
        int at(int i) const
        {
            return v_[i];
        }
        
    private:
        void build(void)
        {
            v_ = new int [sz_];
        }
        
        void destroy(void)
        {
            if (v_ != NULL)
                delete [] v_;
        }
};

class matrix_t {
    private:
        vector_t v_;
        int      m_;
        int      n_;
        
    public:
        matrix_t(int m, int n):
        v_(m * n),
        m_(m),
        n_(n) {}
        
        ~matrix_t(void) {}
        
        int get_m(void) const 
        {
            return m_;
        }
        
        int get_n(void) const
        {
            return n_;
        }

        int& at(int i, int j)
        {
            return v_.at(pos(i, j));
        }
        
        int at(int i, int j) const
        {
            return v_.at(pos(i, j));
        }
        
        void write(ostream& os) const
        {
            for(int i = 1; i <= get_m(); i++) {
                for(int j = 1; j <= get_n(); j++)
                    os << setw(4) << at(i,j) << " ";
                    
                os << endl;
            }
        }
        
        void init_random(int seed)
        {
            srand (seed);
            
            for(int i = 1; i <= get_m(); i++) 
                for(int j = 1; j <= get_n(); j++)
                     at(i,j) = rand() % MAX_VAL;
        }
        
        int suma_total(void) const
        {
            int sum = 0;
            
            for(int i = 1; i <= get_m(); i++) 
                for(int j = 1; j <= get_n(); j++)
                    sum += at(i,j);
                    
            return sum;
        }
        
        int suma_ind_par(void) const
        {
            int sum = 0;
            
            for(int i = 1; i <= get_m(); i++) 
                for(int j = 1; j <= get_n(); j++)
                    if ((i + j) % 2 == 0)
                        sum += at(i,j);
                        
            return sum;
        }        
    
        int suma_diag_p(void) const
        {
            assert(get_m() == get_n());
            
            int sum = 0;
            
            for(int i = 1; i <= get_m(); i++) 
                sum += at(i,i);
                        
            return sum;
        } 
        
        int suma_diag_s(void) const
        {
            assert(get_m() == get_n());
            
            int sum = 0;
            
            for(int i = 1; i <= get_m(); i++) 
                sum += at(i,get_n() - i + 1);
                        
            return sum;
        }         
        
        int suma_tria_inf_diag(void) const
        {
            assert(get_m() == get_n());
            
            int sum = 0;
            
            for(int i = 1; i <= get_m(); i++) 
                for(int j = 1; j <= i; j++)
                        sum += at(i,j);
                        
            return sum;
        }     
        
        int suma_tria_inf(void) const
        {
            assert(get_m() == get_n());
            
            int sum = 0;
            
            for(int i = 2; i <= get_m(); i++) 
                for(int j = 1; j < i; j++)
                        sum += at(i,j);
                        
            return sum;
        }        
        
        int suma_tria_sup_diag(void) const
        {
            assert(get_m() == get_n());
            
            int sum = 0;
            
            for(int i = 1; i <= get_m(); i++) 
                for(int j = i; j <= get_n(); j++)
                        sum += at(i,j);
                        
            return sum;
        }     
        
        int suma_tria_sup(void) const
        {
            assert(get_m() == get_n());
            
            int sum = 0;
            
            for(int i = 1; i < get_m(); i++) 
                for(int j = i + 1; j <= get_n(); j++)
                        sum += at(i,j);
                        
            return sum;
        }          
        
    private:
        int pos(int i, int j) const
        {
            return (i - 1) * n_ + j;
        }
        
};


int main(void)
{
    matrix_t A(5,5);
    
    A.init_random(1);
    
    A.write(cout);
    
    cout << "Suma total                        : " << setw(5) << A.suma_total()   << endl;
    cout << "Suma índice par                   : " << setw(5) << A.suma_ind_par() << endl;
    cout << "Suma diagonal principal           : " << setw(5) << A.suma_diag_p()  << endl;
    cout << "Suma diagnoal secundaria          : " << setw(5) << A.suma_diag_s()  << endl;
    cout << "Suma triangular inf. con diagonal : " << setw(5) << A.suma_tria_inf_diag() << endl;
    cout << "Suma triangular inf. sin diagonal : " << setw(5) << A.suma_tria_inf() << endl;    
    cout << "Suma triangular sup. con diagonal : " << setw(5) << A.suma_tria_sup_diag() << endl;
    cout << "Suma triangular sup. sin diagonal : " << setw(5) << A.suma_tria_sup() << endl;
    
    return 0;
}

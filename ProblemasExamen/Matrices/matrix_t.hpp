#pragma once 

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>

#include <vector>

using namespace std;

template <class T>
class matrix_t
{
private:
        int m_;
        int n_;
        
        vector<T> v_;
        
public:
        matrix_t(void):
        m_(0),
        n_(0),
        v_() {}
        
        matrix_t(int m, int n):
        m_(m),
        n_(n),
        v_(m * n) {}
        
        ~matrix_t(void)
        {}
        
        void resize(int m, int n)
        {
            v_.resize(m * n);
            m_ = m; n_ = n;
        }
        
        T& at (int i, int j)
        {
            return v_.at(pos(i,j));
        }

        const T& at (int i, int j) const
        {
            return v_.at(pos(i,j));
        }   
        
        T& operator()(int i, int j)
        {
            return at(i,j);
        }
        
        const T& operator()(int i, int j) const
        {
            return at(i,j);
        }        
        
        int get_m(void) const 
        {
            return m_;
        }
        
        int get_n(void) const
        {
            return n_;
        }
        
        void write(ostream& os) const
        {
            
             for(int i = 1; i <= m_; i++){
                 for(int j = 1; j <= n_; j++)
                          os << setw(4) << at(i, j) << "  ";
                     
                os << endl;
             }      
        }
        
        // Rellena la matriz con un valor
        
        void fill(const T& val){
            
            for(int i = 1; i <= m_; i++)
                for(int j = 1; j <= n_; j++)
                    at(i,j) = val;
        }
        
        // Devuelve la columna de la diagonal principal correspondiente a la fila i
        
        int columnDP(int i) const
        {
            return i;
        }
        
        // Devuelve la columna de la diagonal secundaria correspondiente a la fila i
        
        int columnDS(int i) const
        {
            return m_ - i + 1;
        }
        
        // Devuelve la fila de la diagonal principal correspondiente a la columna i
        
        int rowDP(int j) const
        {
            return j;
        }
        
        // Devuelve la fila de la diagonal secundaria correspondiente a la columna i
        
        int rowDS(int j) const
        {
            return n_ - j + 1;
        }
        
        // Crea la matriz Norte con Diagonal a partir de la matrix invocante
        
        void N_D(matrix_t<T>& M) const
        {
            assert(m_ == n_);
            
            M.resize(m_, n_);
            M.fill(0);
            
            for(int i = 1; i <= ceil(m_ / 2.0); i++)
                for(int j = columnDP(i); j <= columnDS(i); j++)
                    M(i,j) = at(i,j);        
        }        
        
        // Crea la matriz Norte sin Diagonal a partir de la matrix invocante
        
        void N_ND(matrix_t<T>& M) const
        {
            assert(m_ == n_);
            
            M.resize(m_, n_);
            M.fill(0);
            
            for(int i = 1; i <= ceil(m_ / 2.0); i++)
                for(int j = columnDP(i) + 1; j <= columnDS(i) - 1; j++)
                    M(i,j) = at(i,j);        
        }
        
        // Crea la matriz Sur con Diagonal a partir de la matrix invocante
        
        void S_D(matrix_t<T>& M) const
        {
            assert(m_ == n_);
            
            M.resize(m_, n_);
            M.fill(0);
            
            for(int i = ceil(m_ / 2.0); i <= m_; i++)
                for(int j = columnDS(i); j <= columnDP(i); j++)
                    M(i,j) = at(i,j);        
        }        
        
        // Crea la matriz Sur sin Diagonal a partir de la matrix invocante
        
        void S_ND(matrix_t<T>& M) const
        {
            assert(m_ == n_);
            
            M.resize(m_, n_);
            M.fill(0);
            
            for(int i = ceil(m_ / 2.0); i <= m_; i++)
                for(int j = columnDS(i) + 1; j <= columnDP(i) - 1; j++)
                    M(i,j) = at(i,j);        
        }        
        
        // Crea la matriz Oeste con Diagonal a partir de la matrix invocante
        
        void W_D(matrix_t<T>& M) const
        {
            assert(m_ == n_);
            
            M.resize(m_, n_);
            M.fill(0);
            
            for(int j = 1; j <= ceil(n_ / 2.0); j++)
                for(int i = rowDP(j); i <= rowDS(j); i++)
                    M(i,j) = at(i,j);        
        }  
        
        // Crea la matriz Oeste sin Diagonal a partir de la matrix invocante
        
        void W_ND(matrix_t<T>& M) const
        {
            assert(m_ == n_);
            
            M.resize(m_, n_);
            M.fill(0);
            
            for(int j = 1; j <= ceil(n_ / 2.0); j++)
                for(int i = rowDP(j) + 1; i <= rowDS(j) - 1; i++)
                    M(i,j) = at(i,j);        
        }         
        
        // Crea la matriz Este con Diagonal a partir de la matrix invocante
        
        void E_D(matrix_t<T>& M) const
        {
            assert(m_ == n_);
            
            M.resize(m_, n_);
            M.fill(0);
            
            for(int j = ceil(n_ / 2.0); j <= n_; j++)
                for(int i = rowDS(j); i <= rowDP(j); i++)
                    M(i,j) = at(i,j);        
        }  
        
        // Crea la matriz Este sin Diagonal a partir de la matrix invocante
        
        void E_ND(matrix_t<T>& M) const
        {
            assert(m_ == n_);
            
            M.resize(m_, n_);
            M.fill(0);
            
            for(int j = ceil(n_ / 2.0); j <= n_; j++)
                for(int i = rowDS(j) + 1; i <= rowDP(j) - 1; i++)
                    M(i,j) = at(i,j);        
        }         
        
        
        // Crea submatriz triangular superior incluyendo la diagonal principal 
        // a partir de la matriz invocante
        
        void TSD(matrix_t<T>& M) const
        {
            assert(m_ == n_);
            
            M.resize(m_, n_);
            M.fill(0);
            
            for(int i = 1; i <= m_; i++)
                for(int j = i; j <= n_; j++)
                     M(i,j) = at(i,j); 
        }
        
        // Crea submatriz triangular superior excluyendo la diagonal principal 
        // a partir de la matriz invocante        
        
        void TSND(matrix_t<T>& M) const
        {
            assert(m_ == n_);
            
            M.resize(m_, n_);
            M.fill(0);
            
            for(int i = 1; i <= m_ - 1; i++)
                for(int j = i + 1; j <= n_; j++)
                     M(i,j) = at(i,j); 
        }    
        
        // Crea submatriz triangular inferior incluyendo la diagonal principal 
        // a partir de la matriz invocante
        
        void TID(matrix_t<T>& M) const
        {
            assert(m_ == n_);
            
            M.resize(m_, n_);
            M.fill(0);
            
            for(int i = 1; i <= m_; i++)
                for(int j = 1; j <= i; j++)
                     M(i,j) = at(i,j); 
        }  
        
        // Crea submatriz triangular inferior excluyendo la diagonal principal 
        // a partir de la matriz invocante
        
        void TIND(matrix_t<T>& M) const
        {
            assert(m_ == n_);
            
            M.resize(m_, n_);
            M.fill(0);
            
            for(int i = 2; i <= m_; i++)
                for(int j = 1; j <= i - 1; j++)
                     M(i,j) = at(i,j); 
        }         
             
        
        
        // Producto entre dos matrices multiplicables A y B, almacenando el resultado en la
        // matriz invocante
        
        void producto(const matrix_t<T>& A, const matrix_t<T>& B)
        {
            assert(A.get_n() == B.get_m());
            
            resize(A.get_m(), B.get_n());
            
            for(int i = 1; i <= m_; i++)
                for(int j = 1; j <= n_; j++) {
                    
                    T aux = 0;
                    
                    for(int k = 1; k <= A.get_n(); k++)
                        aux = aux + A(i,k) * B(k,j);
                        
                    at(i,j) = aux;
                }
        }
        
        // Calcula el determinante de la matriz invocante mediante un algoritmo recursivo.
        // 
        // Métodos implicados:
        // double determinante(void) const
        // double coef(int i, int j) const
        // void menor(matrix_t& M, int r) const
        
        double determinante(void) const
        {
            assert(m_ == n_);
            
            if (m_ == 1) return at(1,1);
            
            double suma = 0;
            
            for(int i = 1; i <= m_; i++) {
                
                matrix_t M_aux;
                
                menor(M_aux, i);
                
                suma += at(i, 1) * coef (i,1) * M_aux.determinante();
            }
            
            return suma;
        }
        
        // Devuelve (-1)^(i + j)
        
        double coef(int i, int j) const
        {
            return (i + j) % 2 == 0? 1: -1;
        }
        
        // Construye una nueva matriz M resultante de eliminar la fila r y la primera columna
        
        void menor(matrix_t& M, int r) const
        {
            assert(m_ == n_);
            
            M.resize(m_ - 1, n_ - 1);
            
            int inc_r = 0;
            
            for(int i = 1; i <= M.get_m(); i++) {
                
                if (i == r) inc_r = 1;
                
                for(int j = 1; j <= M.get_n(); j++)
                    M(i,j) = at(i + inc_r, j + 1);
            }
            
        }        
private:

        int pos(int i, int j) const
        {
            return (i - 1) * n_ + j - 1;
        }
        
};

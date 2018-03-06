#pragma once 

#include <cstdio>
#include <iostream>
#include <iomanip>


using namespace std;

template <class T>
class matrix_t
{
private:
        int m_;
        int n_;
        
        T* v_;
        
public:
        matrix_t(void):
        m_(0),
        n_(0),
        v_(NULL) {}
        
        matrix_t(int m, int n):
        m_(m),
        n_(n),
        v_(NULL) {
		build();
            }
        
        ~matrix_t(void)
        {
            destroy();
        }
        
        void resize(int m, int n)
        {
            destroy();
            m_ = m; n_ = n_;

            build();
        }
        
        T& get_set (int i, int j)
        {
            return v_[pos(i,j)];
        }

        T get (int i, int j) const
        {
            return v_[pos(i,j)];
        }        
        
        int get_m(void) const 
        {
            return m_;
        }
        
        int get_n(void) const
        {
            return n_;
        }
        
        ostream& write(ostream& os) const
        {

            os << setw(4) << m_ << endl;
            os << setw(4) << n_ << endl;
            os << endl;
            
             for(int i = 1; i <= m_; i++){
                 for(int j = 1; j <= n_; j++)
                          os << v_[pos(i, j)] << " ";
                     
                os << endl;
             }      

            return os;
        }

        istream& read(istream& is)
        {
             destroy();
            
            is >> m_;
            is >> n_;
            
            build();
            
             for(int i = 1; i <= m_; i++)
                 for(int j = 1; j <= n_; j++)
                        is >> v_[pos(i, j)];
            
            return is;
        }
   
        int pos(int i, int j) const
        {
            return (i -1)* n_ + j - 1;
        }
     
private:
        
        void build(void)
        {
            v_ = new T [m_ * n_];
        }
        
        void destroy(void)
        {
            if (v_)
                delete  [] v_;
        }
};

template <>
ostream&  matrix_t<int>::write(ostream& os) const
{

    os << setw(4) << m_ << endl;
    os << setw(4) << n_ << endl;
    os << endl;
    
     for(int i = 1; i <= m_; i++){
         for(int j = 1; j <= n_; j++)
                  os << setw(5) << v_[pos(i, j)] << " ";
             
        os << endl;
     }      

    return os;
}

template <>
ostream&  matrix_t<double>::write(ostream& os) const
{

    os << setw(4) << m_ << endl;
    os << setw(4) << n_ << endl;
    os << endl;
    
     for(int i = 1; i <= m_; i++){
         for(int j = 1; j <= n_; j++)
                 os << setw(10)<< fixed << setprecision(4) << v_[pos(i, j)] << " ";
             
        os << endl;
     }      

    return os;
}






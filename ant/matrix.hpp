#pragma once 

#include <cstdio>
#include <cassert>
#include "vector.hpp"

using namespace std;

namespace AEDA {

	template <class T>
	class matrix: protected vector<T>
	{
	private:
		    size_t m_;
		    size_t n_;
		    
	public:
		    matrix(size_t m, size_t n):
			vector<T>(m * n),
		    m_(m),
		    n_(n) {}

		    ~matrix(void){}
                
                void resize(size_t m, size_t n)
                {
                      matrix aux(*this);
                      vector<T>::destroy();
                      
                      vector<T>::resize(m_ * n_);
                      const size_t rm = min(m, m_);
                      const size_t rn = min(n, n_);
                      
                      for(size_t i = 1; i <= rm; i++)
                            for(size_t j = 1; j <= rn; j++)
                                  at(i,j) = aux.at(i, j);
                      
                      m_ = m;
                      n_ = n;
                }
		    
		    T& at(size_t i, size_t j)
		    {
				assert(i >= 1);
				assert(i <= n_);
				assert(j >= 1);
				assert(j <= m_);

		        return vector<T>::at(pos(i,j));
		    }

		    const T& at(size_t i, size_t j) const
		    {
				assert(i >= 1);
				assert(i <= n_);
				assert(j >= 1);
				assert(j <= m_);

		        return vector<T>::at(pos(i,j));
		    }        
		    
		    size_t get_m(void) const 
		    {
		        return m_;
		    }
		    
		    size_t get_n(void) const
		    {
		        return n_;
		    }
		 
		    T& operator()(size_t i, size_t j)
		    {
			return at(i,j);
		    }

		    const T& operator()(size_t i, size_t j) const
		    {
			return at(i,j);
		    }

	private:
		    
		    size_t pos(size_t i, size_t j) const
		    {
		        return (i -1)* n_ + j - 1;
		    }
	};

}


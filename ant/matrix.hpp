#pragma once 

#include <cstdio>
#include <cassert>
#include "vector.hpp"

using namespace std;

namespace AEDA {

	template <class T>
	class matrix: private vector<T>
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
		    
		    T& get(size_t i, size_t j)
		    {
				assert(i >= 1);
				assert(i <= n_);
				assert(j >= 1);
				assert(j <= m_);

		        return vector<T>::get(pos(i,j));
		    }

		    const T& get(size_t i, size_t j) const
		    {
				assert(i >= 1);
				assert(i <= n_);
				assert(j >= 1);
				assert(j <= m_);

		        return vector<T>::get(pos(i,j));
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
			return get(i,j);
		    }

		    const T& operator()(size_t i, size_t j) const
		    {
			return get(i,j);
		    }

	private:
		    
		    size_t pos(size_t i, size_t j) const
		    {
		        return (i -1)* n_ + j - 1;
		    }
	};

}


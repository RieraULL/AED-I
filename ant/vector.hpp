#pragma once

#include <cstdio>
#include <cassert>

using namespace std;

namespace AEDA {

	template <class T>
	class vector{

	private:
		T*      v_;
		size_t  sz_;

	public:
		vector(size_t sz):
			v_(NULL),
			sz_(sz) {

			v_ = new T[sz_];
		}

		~vector(void){

			if (v_ != NULL){
				delete [] v_;
				v_ = NULL;
			}
		}

		size_t size(void) const
		{
			return sz_;
		}

		const T& get(size_t pos) const{
		
			assert(pos < sz_);

			return v_[pos];
		}

		T& get(size_t pos){

			assert(pos < sz_);

			return v_[pos];
		}

		T& operator[](size_t pos){
			return get(pos);
		}

		const T& operator[](size_t pos) const {
			return get(pos);
		}
	};
}




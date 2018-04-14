#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>

#include <cassert>

#define MAX_VAL 100
#define VECTOR_SZ 10

using namespace std;

namespace AED {

template <class T>
class vector_t{
private:
	T*      v_;
	int     sz_;

public:

	vector_t(void):
		v_(NULL),
		sz_(0) {}

	vector_t(int sz):
		v_(NULL),
		sz_(sz) {

		crea_vector();
	}

	~vector_t(void){

		destruye_vector();
	}

	void resize(int sz)
	{
		destruye_vector();
		sz_ = sz;
		crea_vector();
	}

	int size(void) const
	{
		return sz_;
	}

	void init_random(int max)
	{
		for(int i = 0; i < sz_; i++)
			at(i) = rand() % max + 1;
	}

	const T& at(int pos) const{
		
		assert((pos < sz_) && ((pos >= 0)));

		return v_[pos];
	}

	T& at(int pos){

		assert((pos < sz_) && ((pos >= 0)));

		return v_[pos];
	}
	
	const T& operator[](int pos) const {
		return at(pos);
	}
	
	T& operator[](int pos) {
		return at(pos);
	}

	ostream& write(ostream& os) const{
	
		for(int i = 0; i < sz_; i ++)
		 	os << v_[i] << " ";


		return os;
	}


private:

	void crea_vector(void){
		v_ = new T[sz_];
	}

	void destruye_vector(void)
	{
		if (v_ != NULL){
			delete [] v_;
			v_ = NULL;
		}
	}

};

template <>
ostream& vector_t<int>::write(ostream& os) const{

	for(int i = 0; i < sz_; i ++)
	 	os << setw(3) << v_[i] << " ";

	return os;
}

ostream& operator<<(ostream& os, const vector_t<int>& v)
{
	v.write(os);
	return os;
}

template<class T>
void swap(T& a, T& b)
{
	T aux = a;
	a = b;
	b = aux;
}

template<class T>
bool unordered(const T& a, const T& b)
{
	return a > b;
}

template<class T>
void biggest_2_end(vector_t<T>& v, int end_v)
{
	for(int i = 0; i <= end_v - 1; i++)
		if (unordered<T>(v[i], v[i + 1]))
			swap<T>(v[i], v[i + 1]);
}

template<class T>
void bubble_sort(vector_t<T>& v)
{
	for(int i = v.size() - 1; i >= 1; i--) {
		 biggest_2_end<T>(v, i);
#ifdef DEBUGGING
		cout << "i: " << i << endl;
		cout << "    " << v << endl; cout << endl;
#endif
	}
}

}

int main(void)
{
	AED::vector_t<int> v(VECTOR_SZ);
	v.init_random(MAX_VAL);

	cout << v << endl;

	AED::bubble_sort(v);

	cout << v << endl;

	return 0;
}



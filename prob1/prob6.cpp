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

	void write(ostream& os) const{
	
		for(int i = 0; i < sz_; i ++)
		 	os << v_[i] << " ";
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
void vector_t<int>::write(ostream& os) const{

	for(int i = 0; i < sz_; i ++)
	 	os << setw(3) << v_[i] << " ";
}

ostream& operator<<(ostream& os, const vector_t<int>& v)
{
	v.write(os);
	return os;
}

template <class T>
class sorted_container_t
{
private:
	vector_t<T> container_;
	int last_;

public:
	sorted_container_t(int sz):
	container_(sz),
	last_(-1) {}

	~sorted_container_t(void) {}

	bool full(void)  {return (last_ >= (container_.size() - 1));}
	bool empty(void) {return last_ <= -1;}

	void insert(const T& d)
	{
		assert(!full());

		const int pos = get_pos(d);

		shift(pos);

		container_[pos] = d;
	}		

	int get_pos(const T& d)
	{
		int pos = 0;

		while ((pos <= last_) && (container_[pos] < d))
			pos ++;

        return pos;
	}

	void shift(int pos) 
	{				
		last_ ++;
	
		for(int i = last_; i > pos; i--)
			container_[i] = container_[i - 1];		
	}

	void write(ostream& os) const
	{
		for(int i = 0; i <= last_; i++)
			cout << container_[i] << " ";
	}
};

template <>
void sorted_container_t<int>::write(ostream& os) const
{
	for(int i = 0; i <= last_; i++)
		cout << setw(3) << container_[i] << " ";
}

ostream& operator<<(ostream& os, const sorted_container_t<int>& v)
{
	v.write(os);
	return os;
}

}

int main(void)
{
	AED::sorted_container_t<int> v(VECTOR_SZ);

	for(int i = 0; i < VECTOR_SZ; i++) {
		
		const int d = rand() % MAX_VAL + 1;

		cout << "Insertando: " << d << endl;
		
		v.insert(d);

		cout << v << endl;
	}


	return 0;
}



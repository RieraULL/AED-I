#include <cstdio>
#include <iostream>
#include <iomanip>

#include <cassert>

using namespace std;

template <class T>
class vector_t
{
private:
      T*      v_;
      
      int     l_;
      int     r_;

public:

      vector_t(void):
            v_(NULL),
            l_(0),
            r_(-1) {}

      vector_t(int sz):
            v_(NULL),
            l_(0),
            r_(sz - 1)
      {
            build();
      }

      vector_t(int l, int r):
            v_(NULL),
            l_(l),
            r_(r)
      {
            assert (l <= r);
            build();
      }
      
      vector_t(const vector_t<T>& v):
      v_(NULL),
      l_(v.l_),
      r_(v.r_)
      {
            build();
            
            for(int i = l_; i <= r_; i++)
                  at(i) = v.at(i);
      }

      ~vector_t(void)
      {
            destroy();
      }
      
      int left(void) const
      {
            return l_;
      }
      
      int right(void) const
      {
            return r_;
      }

      int size(void) const
      {
            return r_ - l_ + 1;
      }
      
      void init(const T& val)
      {
            for(int i = l_; i <= r_; i++)
                  at(i) = val;
      }

      const T& at(int pos) const
      {
            assert((pos <= r_) && ((pos >= l_)));
            return v_[pos - l_];
      }

      T& at(int pos)
      {
            assert((pos <= r_) && ((pos >= l_)));
            return v_[pos - l_];
      }
      
      void suma(const vector_t<T>& v, const vector_t<T>& w)
      {
            l_ = (v.l_ < w.l_)? v.l_: w.l_;
            r_ = (v.r_ > w.r_)? v.r_: w.r_;
            
            resize();
            init(0);
            
            for(int i = v.l_; i <= v.r_; i++)
                  at(i) = v.at(i);
                  
            for(int i = w.l_; i <= w.r_; i++)
                  at(i) += w.at(i);
      }

      const T& operator[](int pos) const
      {
            return at(pos);
      }

      T& operator[](int pos)
      {
            return at(pos);
      }
      
      vector_t<T>& operator=(const vector_t<T>& v)
      {
            destroy();
            
            l_ = v.l_;
            r_ = v.r_;
            
            build();
            
            for(int i = 0; i < size(); i++)
                  v_[i] = v.v_[i];
                  
            return (*this);
      }
      
      void write(ostream& os)
      {
            for(int i = l_; i < r_; i++)
                  os << "(" << setw(4) << i << " " << setw(4) << at(i) << ") ";
      }

private:

      void resize(void)
      {
            destroy();
            build();
      }

      void build(void)
      {
            v_ = new T[size()];
      }

      void destroy(void)
      {
            if (v_ != NULL) {
                  delete [] v_;
                  v_ = NULL;
            }
      }

};



int main(void)
{
      
      vector_t<int> v(-10, 10);
      vector_t<int> w(5, 20);
      
      for(int i = v.left(); i <= v.right(); i++)
            v[i] = -i;
            
      v.write(cout);
      cout << endl;

      for(int i = w.left(); i <= w.right(); i++)
            w[i] = -i;
            
      w.write(cout);
      cout << endl;
      
      vector_t<int> x;
      
      x.suma(v, w);
      
      x.write(cout);
      cout << endl;     
      
      return 0;
}


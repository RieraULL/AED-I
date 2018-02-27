#pragma once

#include <cstdio>
#include <cassert>

using namespace std;

namespace AEDA
{

template <class T>
class vector
{

private:
      T*      v_;
      size_t  sz_;

public:
      vector(size_t sz):
            v_(NULL),
            sz_(sz)
      {

            build();
      }

      vector(const vector& v):
            v_(NULL),
            sz_(v.sz_)
      {

            build();

            for(size_t i = 0; i < sz_; i++)
                  v_[i] = v.v_[i];
      }

      ~vector(void)
      {
            destroy();
      }

      void resize(size_t sz)
      {
            destroy();
            sz_ = sz;
            build();
      }

      size_t size(void) const
      {
            return sz_;
      }

      const T& at(size_t pos) const
      {
            assert(pos < sz_);
            return v_[pos];
      }

      T& at(size_t pos)
      {
            assert(pos < sz_);
            return v_[pos];
      }

      T& operator[](size_t pos)
      {
            return at(pos);
      }

      const T& operator[](size_t pos) const
      {
            return at(pos);
      }
      
      T& operator=(const vector& v)
      {
            destroy();
            sz_ = v.sz_;
            build();
            
            for(int i = 0; i < sz_; i++)
                  v_[i] = v.v_[i];

            return (*this);
      }

protected:
      void build(void)
      {
            v_ = new T[sz_];
      }

      void destroy(void)
      {
            if (v_ != NULL) {
                  delete [] v_;
                  v_ = NULL;
            }
      }
};
}

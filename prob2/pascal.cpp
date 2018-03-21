#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

typedef unsigned long binomial_number_t;

template <class T>
class vector_t
{
private:

    T* base_;
    size_t  sz_;

public:

    vector_t(size_t sz):
        base_(NULL),
        sz_(sz)
    {
        build(sz_);
    }

    ~vector_t(void)
    {
        destroy();
    }

    size_t size(void) const
    {
        return sz_;
    }

    T& at(size_t i)
    {
        assert(i < sz_);
        return base_[i];
    }

    const T& at(size_t i) const
    {
        assert(i < sz_);
        return base_[i];
    }

private:

    void build(size_t sz)
    {
        base_ = new T [sz];
    }

    void destroy(void)
    {
        if (base_ != NULL) {
            delete [] base_;
            base_ = NULL;
        }
    }
};


class pascal_triangle_t
{
private:
    vector_t<binomial_number_t>     v_;
    const size_t                    n_;
    
public:
    pascal_triangle_t(size_t n);
    ~pascal_triangle_t(void);

    size_t get_n(void);

    void write(ostream& os) const;

    binomial_number_t at(size_t i, size_t j) const;
    binomial_number_t& at(size_t i, size_t j);

private:
    void build_triangle(size_t n);
    size_t pos(size_t i, size_t j) const;
    inline size_t S(size_t n) const;
    void init_row(size_t i);
    size_t pos(size_t i) const;
};

pascal_triangle_t::pascal_triangle_t(size_t n):
    v_(S(n)),
    n_(n)
{
    build_triangle(n);
}

pascal_triangle_t::~pascal_triangle_t(void) {}

size_t pascal_triangle_t::get_n(void)
{
    return n_;
}

void pascal_triangle_t::pascal_triangle_t::write(ostream& os) const
{
    for(size_t i = 0; i < n_; i++) {
        for(size_t j = 0; j <= i; j++)
            os << setw(8) << at(i,j);
        os << endl;
    }
}

binomial_number_t pascal_triangle_t::at(size_t i, size_t j) const
{
    return v_.at(pos(i, j));
}

binomial_number_t& pascal_triangle_t::at(size_t i, size_t j)
{
    return v_.at(pos(i, j));
}

void pascal_triangle_t::build_triangle(size_t n)
{
    at(0, 0) = 1;
    for(size_t i = 1; i < n; i++) {
        init_row(i);
        for(size_t j = 1; j < i ; j++)
            at(i, j) = at(i - 1, j - 1) + at(i - 1, j);
    }
}

size_t pascal_triangle_t::pos(size_t i, size_t j) const
{
    assert(i < n_);
    assert(j <= i);
    return S(i) + j;
}

size_t pascal_triangle_t::S(size_t n) const
{
    return n * (n + 1) * 0.5;
}

void pascal_triangle_t::init_row(size_t i)
{
    at(i, 0) = 1;
    at(i, i) = 1;
}



class binomial_t
{
private:
    pascal_triangle_t T_;

public:
    binomial_t(size_t n);
    ~binomial_t(void);

    binomial_number_t C(size_t n, size_t k) const;
};

binomial_t::binomial_t(size_t n):
    T_(n + 1) {}

binomial_t::~binomial_t(void) {}

binomial_number_t binomial_t::C(size_t n, size_t k) const
{
    if (n == 0) return 0;
    if (k == 0) return 1;

    return T_.at(n, k);
}

int main(void)
{
    pascal_triangle_t T(10);
    T.write(cout);
    cout << endl;

    binomial_t B(10);

    cout << B.C(10,2) << endl;
    cout << B.C( 5,2) << endl;

    return 0;
}

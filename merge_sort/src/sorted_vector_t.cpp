#include "sorted_vector_t.hpp"

#include <climits>
#include <iomanip>

namespace CyA
{

void sorted_vector_t::merge_sort(void)
{
    merge_sort(0, size() - 1);
}

void sorted_vector_t::write(ostream& os) const
{
    const int sz = size();

    os << "< ";
    for(int i = 0; i < sz; i++)
        os << setw(5) << at(i);
    os << "> ";
}


void sorted_vector_t::merge_sort(int l, int r)
{
    if (l < r) {
        
        int c = (l + r) / 2;

        merge_sort(l, c);

        merge_sort(c + 1, r);

        merge(l, c, r);
    }
}


////////////////////////////////////////////////////////////////////////////
// FUSIÓN CON CENTINELA
////////////////////////////////////////////////////////////////////////////

void sorted_vector_t::create_vector_sentinel(int l, int r, vector<int>& v)
{

}

void sorted_vector_t::merge(int l, int c, int d)
{
 
}

////////////////////////////////////////////////////////////////////////////

}


ostream& operator<<(ostream& os, const CyA::sorted_vector_t& v)
{
    v.write(os);
    return os;
}

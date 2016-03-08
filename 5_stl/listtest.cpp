
#include "listtest.h"

#ifdef LIST_TEST_ITERATOR_SWAP
void listtest::sort(std::list<std::string> &v)
{
    for(auto q = begin(v); q != end(v); ++ q)
        for(auto p = begin(v); p != q; ++ p)
            if(*p > *q)
                std::swap(*p, *q);
}

#endif // LIST_TEST_ITERATOR_SWAP

#ifdef LIST_TEST_ITERATOR_ASSIGN
void listtest::sort(std::list<std::string> &v)
{
    for(auto q = begin(v); q != end(v); ++ q)
        for(auto p = begin(v); p != q; ++ p)
            if(*p > *q)
            {
                auto t = *p;
                *p = *q;
                *q = t;
            }
}

#endif // LIST_TEST_ITERATOR_ASSIGN

std::ostream&
operator << ( std::ostream& stream, const std::list< std::string > & lst)
{
    for(auto &elem: lst)
        stream << elem << " ";

    return stream;
}


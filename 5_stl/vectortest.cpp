
#include "vectortest.h"

#ifdef VECTOR_TEST_INDEX_SWAP
void vectortest::sort(std::vector<std::string> &v)
{
    for(size_t j = 0; j < v.size(); ++ j)
        for(size_t i = 0; i < j; ++ i)
            if(v[i] > v[j])
                std::swap(v[i], v[j]);
}

#endif // VECTOR_TEST_INDEX_SWAP

#ifdef VECTOR_TEST_INDEX_ASSIGN
void vectortest::sort(std::vector<std::string> &v)
{
    for(size_t j = 0; j < v.size(); ++ j)
        for(size_t i = 0; i < j; ++ i)
            if(v[i] > v[j])
            {
                auto t = v[i];
                v[i] = v[j];
                v[j] = t;
            }
}

#endif // VECTOR_TEST_INDEX_ASSIGN

#ifdef VECTOR_TEST_ITERATOR_SWAP
void vectortest::sort(std::vector<std::string> &v)
{
    for(auto q = begin(v); q != end(v); ++ q)
        for(auto p = begin(v); p != q; ++ p)
            if(*p > *q)
                std::swap(*p, *q);
}

#endif // VECTOR_TEST_ITERATOR_SWAP

#ifdef VECTOR_TEST_ITERATOR_ASSIGN
void vectortest::sort(std::vector<std::string> &v)
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

#endif // VECTOR_TEST_ITERATOR_ASSIGN

#ifdef VECTOR_TEST_STL_SORT
#include <algorithm>
void vectortest::sort(std::vector<std::string> &v)
{
    std::sort(begin(v), end(v));
}

#endif // VECTOR_TEST_STL_SORT

std::ostream&
operator << ( std::ostream& stream, const std::vector< std::string > & vec)
{
    for(auto &elem: vec)
        stream << elem << " ";

    return stream;
}



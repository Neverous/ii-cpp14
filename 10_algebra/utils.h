#ifndef __UTILS_H__
#define __UTILS_H__

template<typename ITERATOR, typename JOIN, typename EQ>
inline
ITERATOR join_equal(ITERATOR from, ITERATOR to, JOIN join, EQ equal)
{
    ITERATOR dest = from;
    if(from == to)
        return from;

    while(++ from != to)
    {
        if(equal(*from, *dest))
            join(*dest, *from);

        else
            *(++ dest) = std::move(*from);
    }

    return ++ dest;
}

#endif // __UTILS_H__

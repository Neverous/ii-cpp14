#include <iostream>

struct xx
{
    int val;
    static unsigned int copied;
    static unsigned int moved;

    explicit xx(int val);
    xx(xx &&src) noexcept;
    xx(const xx &src);
}; // struct xx

inline
xx::xx(int _val)
:val(_val)
{
}

inline
xx::xx(xx &&src) noexcept
:val(src.val)
{
    std::cout << "MOVE " << this << "\n";
    ++ moved;
}

inline
xx::xx(const xx &src)
:val(src.val)
{
    std::cout << "COPY " << this << "\n";
    ++ copied;
}

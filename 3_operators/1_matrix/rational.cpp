
#include "rational.h"

// Complete these methods:

#if 1
int rational::gcd( int n1, int n2 )
{
    if(n1 < 0)
        n1 *= -1;

    if(n2 < 0)
        n2 *= -1;

    if(n1 > n2)
        std::swap(n1, n2);

    while(n1 > 0)
    {
        int temp = n2 % n1;
        n2 = n1;
        n1 = temp;
    }

    return n2;
}

void rational::normalize( )
{
    int div = gcd(num, denum);
    if(div)
    {
        num /= div;
        denum /= div;
    }

    if(denum < 0)
    {
        num *= -1;
        denum *= -1;
    }
}

rational operator - ( rational r )
{
    return rational{-r.get_num(), r.get_denum()};
}

rational operator + ( const rational& r1, const rational& r2 )
{
    return rational{r1.get_num() * r2.get_denum() + r1.get_denum() * r2.get_num(), r1.get_denum() * r2.get_denum()};
}

rational operator - ( const rational& r1, const rational& r2 )
{
    return rational{r1.get_num() * r2.get_denum() - r1.get_denum() * r2.get_num(), r1.get_denum() * r2.get_denum()};
}

rational operator * ( const rational& r1, const rational& r2 )
{
    return rational{r1.get_num() * r2.get_num(), r1.get_denum() * r2.get_denum()};
}

rational operator / ( const rational& r1, const rational& r2 )
{
    return rational{r1.get_num() * r2.get_denum(), r1.get_denum() * r2.get_num()};
}

bool operator == ( const rational& r1, const rational& r2 )
{
    return  r1.get_num() == r2.get_num()
        &&  r1.get_denum() == r2.get_denum();
}

bool operator != ( const rational& r1, const rational& r2 )
{
    return !(r1 == r2);
}

std::ostream& operator << ( std::ostream& stream, const rational& r )
{
    if(r.get_denum())
        return stream << r.get_num() << "/" << r.get_denum();

    return stream << r.get_num();
}

#endif


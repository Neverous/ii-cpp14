#include<iostream>
#include<vector>
#include "../1_matrix/rational.h"

template<typename Type=rational>
class Polynomial: public std::vector<Type>
{
    using std::vector<Type>::vector; // inherit constructors
}; // class Polynomial<Type>

template<typename Type=rational>
Polynomial<Type> operator*(const Polynomial<Type> &x, const Polynomial<Type> &y)
{
    Polynomial<Type> result; result.resize(x.size() + y.size() - 1);
    for(size_t f = 0; f < x.size(); ++ f)
        for(size_t s = 0; s < y.size(); ++ s)
            result[f + s] = result[f + s] + x[f] * y[s];

    return result;
}

template<typename Type=rational>
std::ostream &operator<<(std::ostream &stream, const Polynomial<Type> &p)
{
    int q = 0;
    for(auto it = begin(p); it != end(p); ++ it, ++ q)
    {
        stream << *it << "*x^" << q;
        if(it + 1 != end(p))
            stream << " + ";
    }

    return stream;
}

int main(void)
{
    {
        Polynomial<double> res{1};
        for(int t = 1; t < 10; ++ t)
            res = res * Polynomial<double>{0.1 * t, 1.};

        std::cout << res << "\n";
    }

    {
        Polynomial<float> res{1};
        for(int t = 1; t < 10; ++ t)
            res = res * Polynomial<float>{0.1f * t, 1.f};

        std::cout << res << "\n";
    }

    {
        Polynomial<rational> res{1};
        for(int t = 2; t < 5; ++ t)
            res = res * Polynomial<rational>{{1, t}, 1};

        std::cout << res << "\n";
    }

    {
        Polynomial<rational> res{1};
        for(int t = 0; t < 5; ++ t)
            res = res * Polynomial<rational>{{1, 2}, 1};

        std::cout << res << "\n";
    }

    return 0;
}


#include "varchain.h"
#include "polynomial.h"
#include "bigint.h"
#include "rational.h"


template< typename N >
polynomial< N > exptaylor( unsigned int n )
{
    varchain v;

    N fact = 1;

    polynomial< N > result;
    for( unsigned int i = 0; i < n; ++ i )
    {
        result[v] += fact;
        v = v * powvar( "x" );
        fact = fact / (i+1);
    }

    return result;
}

int main( int argc, char* argv [] )
{
    std::cout << "hello\n";
    {
        varchain x1{{"", 1}, {"x", 1}};
        std::cout << "test = " << x1 << "\n";
    }

    {
        varchain test{{"x", 7}};
        std::cout << "test = " << test << "\n";
    }

    {
        varchain test{{"y", 5}};
        std::cout << "test = " << test << "\n";
    }

    {
        varchain test{{"y", 5}, {"x", 7}};
        std::cout << "test = " << test << "\n";
    }

    {
        varchain test{{"x", 13}, {"y", 7}, {"z", 0}};
        test = test * test;
        std::cout << "test = " << test << "\n";
    }

    {
        varchain test{};
        std::cout << "test = " << test << "\n";
    }

    {
        varchain a{{"x", 1}};
        varchain b{{"y", 1}};
        std::cout << "test[x < y] = " << varchain::cmp{}(a, b) << "\n";
    }

    {
        polynomial<rational> test;
        std::cout << "test = " << test << "\n";
    }

    {
        polynomial<rational> test2;
        test2[{{"y"}}] = 5;
        test2[{{"p", 8}}] = 9;
        std::cout << "test2 = " << test2 << "\n";
    }

    {
        polynomial<double> x1;
        x1[{}] = 1;
        x1[{"x"}] = 1;
        std::cout << "x1 = " << x1 << "\n";

        polynomial<double> test{{}};
        std::cout << "test = " << test << "\n";
        for(size_t i = 0; i < 5; ++ i)
        {
            test = test * x1;
            std::cout << "test" << i << " = " << test << "\n";
        }
    }

    {
        polynomial<double> x1;
        x1[{}] = 3;
        x1[{{"x"}, {"y"}}] = 1;
        std::cout << "x1 = " << x1 << "\n";

        polynomial<double> test{{}};
        std::cout << "test = " << test << "\n";
        for(size_t i = 0; i < 6; ++ i)
        {
            test = test * x1;
            std::cout << "test" << i << " = " << test << "\n";
        }
    }

    {
        polynomial< rational > pol;

        int N = 200;

        pol[ { } ] = 1;
        pol[ { "x" } ] = rational( 1, N );


        polynomial< rational > res = 1;

        for( int i = 0; i < N; ++ i )
            res = res * pol;

        std::cout << "result = " << res << "\n";

        std::cout << " taylor expansion = " << exptaylor<rational>(20) << "\n";

        std::cout << "difference = " ;
        std::cout << res - exptaylor<rational> ( 40 ) << "\n";
    }

    {
        polynomial< double > pol;

        int N = 75;

        pol[ { } ] = 1;
        pol[ { "x" } ] = 1. / N;


        polynomial< double > res = 1;

        for( int i = 0; i < N; ++ i )
            res = res * pol;

        std::cout << "result = " << res << "\n";

        std::cout << " taylor expansion = " << exptaylor<double>(20) << "\n";

        std::cout << "difference = " ;
        std::cout << res - exptaylor<double> ( 40 ) << "\n";
    }

    return 0;
}



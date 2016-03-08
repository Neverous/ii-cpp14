
#include "rational.h"
#include "matrix.h"

int main( int argc, char* argv [ ] )
{
    rational r1( -2, 6 );
    rational r2( 4, 3 );
    rational r3( 5,6 );
    rational r4( 1, 2 );

    std::cout << r3 << " / " << r1 << " = " << (r3 / r1) << std::endl;
    std::cout << r3 << " - " << r1 << " = " << (r3 - r1) << std::endl;
    std::cout << r3 << " + " << r1 << " = " << (r3 + r1) << std::endl;
    std::cout << r1 << " + " << r3 << " = " << (r1 + r3) << std::endl;
    std::cout << r3 << " * " << r1 << " = " << (r3 * r1) << std::endl;
    std::cout << r1 << " * " << r3 << " = " << (r1 * r3) << std::endl;

    matrix m1 = {{{1, 2}, {-2, 7}}, {{1, 3}, {2, 8}}};
    matrix m2 = {{{-1, 3}, {2, 5}}, {{2, 7}, {-1, 7}}};

    std::cout << m1 * m2 << std::endl;
    std::cout << "INVERSE: " << std::endl;
    std::cout << m1.inverse() << std::endl;

    matrix m3 = {{{2, 5}, {3, 4}}, {{-6, 7}, {7, 9}}};

    matrix A = (m1 * m2) * m3;
    matrix B = m1 * (m2 * m3);
    bool valid = true;
    for(int i = 0; valid && i < 2; ++ i)
        for(int j = 0; valid && j < 2; ++ j)
            valid = A.repr[i][j] == B.repr[i][j];

    std::cout << "associative multiplication:" << valid << std::endl;

    vector v1 = {{5, 6}, {-3, 11}};
    vector v2 = m1(m2(v1));
    vector v3 = (m1 * m2)(v1);
    std::cout << "composition of application:" << (v2.x == v3.x && v2.y == v3.y) << std::endl;
    std::cout << "determinant over multiplication:" << (m1.determinant() * m2.determinant() == (m1 * m2).determinant()) << std::endl;

    A = m2;
    B = A * A.inverse();
    std::cout << "inverse is ok:" << (B.repr[0][0] == 1 && B.repr[0][1] == 0 && B.repr[1][0] == 0 && B.repr[1][1] == 1) << std::endl;

    // ORIGINAL
    {
        rational r1( 2, 6 );
        rational r2( 4, 3 );
        rational r3( 5,6 );
        rational r4( 1, 2 );

        matrix m1 = { { 2, 3 }, { 5, 6 } };
        std::cout << m1 << "\n";

        matrix m2 = { { 5,4 }, { 6, rational(1,2) } };
        std::cout << m2 << "\n";

        matrix m3 = { { 4,5}, { -1, 2 }};

        std::cout << m1. determinant( ) << "\n";

        std::cout << m1. adjugate( ) << "\n";
        std::cout << m1. inverse( ) * m1 << "\n";
    }
}


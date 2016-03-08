
#include "fifteen.h"
#include <algorithm>
#include <iomanip>
#include <cassert>


fifteen::fifteen()
{
    for(size_t h = 0; h < dimension; ++ h)
        for(size_t w = 0; w < dimension; ++ w)
            table[h][w] = 1 + h * dimension + w;

    table[dimension - 1][dimension - 1] = 0;
    open_i = dimension - 1;
    open_j = dimension - 1;
}

fifteen::fifteen(std::initializer_list<std::initializer_list<size_t>> init)
{
    size_t h = 0, w = 0;
    for(const auto &row: init)
    {
        for(const auto &cell: row)
        {
            if(cell == 0)
            {
                open_i = h;
                open_j = w;
            }

            table[h][w ++] = cell;
        }

        assert(w == dimension);
        ++  h;
        w = 0;
    }

    assert(h == dimension);
}

void fifteen::makemove(move m)
{
    int new_open_i = open_i + (m == move::down) - (m == move::up);
    int new_open_j = open_j + (m == move::right) - (m == move::left);
    if(     0 > new_open_i || new_open_i >= (int) dimension
        ||  0 > new_open_j || new_open_j >= (int) dimension)
        throw illegalmove{m};

    std::swap(table[open_i][open_j], table[new_open_i][new_open_j]);
    open_i = new_open_i;
    open_j = new_open_j;
}

size_t fifteen::distance() const
{
    size_t result = 0;
    for(size_t h = 0; h < dimension; ++ h)
        for(size_t w = 0; w < dimension; ++ w)
        {
            int cell = table[h][w] - 1;
            result += (!!table[h][w]) * (std::abs<int>(h - cell / dimension) + std::abs<int>(w - cell % dimension));
        }

    return result;
}

bool fifteen::issolved() const
{
    for(size_t h = 0; h < dimension; ++ h)
        for(size_t w = 0; w < dimension && h * dimension + w + 1 < dimension * dimension; ++ w)
            if(table[h][w] != 1 + h * dimension + w)
                return false;

    assert(table[open_i][open_j] == 0);
    return table[dimension - 1][dimension - 1] == 0;
}

template <class T>
inline
void hash_combine(std::size_t& seed, const T& v)
{
    std::hash<T> hasher{};
    seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

size_t fifteen::hashvalue() const
{
    size_t result = 0;
    for(size_t h = 0; h < dimension; ++ h)
        for(size_t w = 0; w < dimension; ++ w)
            hash_combine(result, table[h][w]);

    return result;
}

bool fifteen::equals(const fifteen& other) const
{
    for(size_t h = 0; h < dimension; ++ h)
        for(size_t w = 0; w < dimension; ++ w)
            if(table[h][w] != other.table[h][w])
                return false;

    assert(open_i == other.open_i && open_j == other.open_j);
    return true;
}

std::ostream& operator<<(std::ostream& stream, const fifteen& f)
{
    for(size_t h = 0; h < f.dimension; ++ h)
        for(size_t w = 0; w < f.dimension; ++ w)
            stream << std::setw(2) << f.table[h][w] << (f.dimension - 1 == w ? '\n' : ' ');

    return stream << "; open_i = " << f.open_i << " open_j = " << f.open_j << "\n";
}

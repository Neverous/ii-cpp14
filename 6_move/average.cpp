#include <iostream>
#include <vector>

#include "../1_matrix/rational.h"

template<typename Type, typename Container=std::vector<Type>>
Type average(const Container &data)
{
    Type result{};
    //for(auto it = begin(data); it != end(data); ++ it)
    //    result += *it;

    for(const auto &value: data)
        result = result + value;

    return result / data.size();
}

template<typename Type, typename Container=std::vector<Type>>
std::ostream &operator<<(std::ostream &stream, const Container &data)
{
    for(const auto &value: data)
        stream << value << " ";

    return stream;
}

int main(void)
{
    {
        std::vector<double> data{1.0, 2.0, 3.6};
        std::cout << average<double>(data) << "\n";
    }

    {
        std::vector<float> data{1.0f, 2.0f, 3.6f};
        std::cout << average<float>(data) << "\n";
    }

    {
        std::vector<rational> data{{1, 2}, {2, 3}, {3, 4}};
        std::cout << average<rational>(data) << "\n";
    }


    {
        std::vector<double> data;
        for(size_t i = 0; i < 1024; ++ i)
            data.push_back(0.1 * i);

        std::cout << average<double>(data) << "\n";
    }

    return 0;
}

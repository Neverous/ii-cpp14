#include <iostream>
#include <list>
#include <random>
#include <vector>
#include "xx.h"

unsigned int xx::copied = 0;
unsigned int xx::moved = 0;

void vector_test(void)
{
    std::vector<xx> data;
    std::random_device rd;
    std::default_random_engine e1(rd());
    std::uniform_int_distribution<int> uniform_dist(1, 1048576);
    for(size_t c = 0; c < 1025; ++ c)
    {
        std::cout << "PUSH_PRE\n";
        data.emplace_back(uniform_dist(e1));
        std::cout << "PUSH_POST\n";
    }

    while(data.size())
    {
        std::cout << "POP_PRE\n";
        data.pop_back();
        std::cout << "POP_POST\n";
    }

    std::cout << "FINAL CAPACITY: " << data.capacity() << "\n";
    std::cout << "RESERVE_PRE\n";
    data = std::vector<xx>();
    data.reserve(1025);
    for(size_t c = 0; c < 1025; ++ c)
    {
        std::cout << "RESERVE_PUSH_PRE\n";
        data.emplace_back(uniform_dist(e1));
        std::cout << "RESERVE_PUSH_POST\n";
    }

    std::cout << "RESERVE_POST\n";
}

void list_test(void)
{
    std::list<xx> data;
    std::random_device rd;
    std::default_random_engine e1(rd());
    std::uniform_int_distribution<int> uniform_dist(1, 1048576);
    for(size_t c = 0; c < 1025; ++ c)
    {
        std::cout << "PUSH_PRE\n";
        data.emplace_back(uniform_dist(e1));
        std::cout << "PUSH_POST\n";
    }

    while(data.size())
    {
        std::cout << "POP_PRE\n";
        data.pop_back();
        std::cout << "POP_POST\n";
    }
}

int main(void)
{
    vector_test();
    list_test();
    return 0;
}

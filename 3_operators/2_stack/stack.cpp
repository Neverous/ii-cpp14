#include <cassert>

#include "stack.h"

Stack::Stack(void)
:current_capacity{0}
,current_size{0}
,data{nullptr}
{

}

Stack::Stack(const Stack &src)
:current_capacity{src.current_size} // OR src.current_capacity
,current_size{src.current_size}
,data{new double[src.current_size]} // OR src.current_capacity
{
    for(size_t d = 0; d < current_size; ++ d)
        data[d] = src.data[d];
}

Stack::Stack(const std::initializer_list<double> &init)
:Stack{}
{
    ensure_capacity(init.size(), false);
    for(double num: init)
        push(num);
}

Stack::~Stack(void)
{
    delete[] data;
    data = nullptr;
    current_capacity = 0;
    current_size = 0;
}

Stack Stack::operator+(const Stack &src) const
{
    Stack res{*this};
    res += src;
    return res;
}


void Stack::operator+=(const Stack &src)
{
    ensure_capacity(current_size + src.current_size);
    for(size_t d = 0, cur_size = src.current_size; d < cur_size; ++ d)
        push(src.data[d]);
}

const double &Stack::operator[](size_t l) const
{
    assert(l < current_size);
    return data[current_size - 1 - l];
}

double &Stack::operator[](size_t l)
{
    assert(l < current_size);
    return data[current_size - 1 - l];
}

void Stack::push(double value)
{
    ensure_capacity(current_size + 1);
    data[current_size ++] = value;
}

void Stack::pop(void)
{
    if(!current_size)
        return;

    -- current_size;
}

double &Stack::top(void)
{
    assert(current_size > 0);
    return data[current_size - 1];
}

const double &Stack::top(void) const
{
    assert(current_size > 0);
    return data[current_size - 1];
}

void Stack::reset(size_t _size)
{
    assert(_size <= current_size);
    current_size = _size;
}

void Stack::ensure_capacity(size_t capacity, bool copy)
{
    if(capacity <= current_capacity)
        return;

    if(capacity < 2 * current_capacity)
        capacity = 2 * current_capacity;

    assert(capacity >= current_size);
    double *new_data = new double[capacity];
    if(copy)
    {
        for(size_t d = 0; d < current_size; ++ d)
            new_data[d] = data[d];
    }

    current_capacity = capacity;
    delete[] data;
    data = new_data;
}

std::ostream &operator<<(std::ostream &stream, const Stack &s)
{
    stream << "[ ";
    for(size_t d = 0; d < s.current_size; ++ d)
        stream << s.data[d] << " ";

    return stream << "]";
}

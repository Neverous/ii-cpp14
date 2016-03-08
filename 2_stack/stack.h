#ifndef __STACK_H__
#define __STACK_H__

#include <cstdlib>
#include <iostream>

class Stack
{
    friend std::ostream &operator<<(std::ostream &stream, const Stack &s);

private:
    size_t  current_capacity;
    size_t  current_size;
    double  *data;

public:
    Stack(void);
    Stack(const Stack &src);
    ~Stack(void);

    void operator=(Stack &&src);
    void operator=(const Stack &src);

    void push(double value);
    void pop(void);

    // Stack has to be nonempty
    double &top(void);
    const double &top(void) const;

    // _size should be smaller than current_size
    void reset(size_t _size);

    size_t size(void) const;
    bool empty(void) const;

private:
    void ensure_capacity(size_t capacity, bool copy = true);
}; // class Stack

inline
void Stack::operator=(Stack &&src)
{
    std::swap(current_capacity, src.current_capacity);
    std::swap(current_size, src.current_size);
    std::swap(data, src.data);
}

inline
void Stack::operator=(const Stack &src)
{
   *this = Stack(src);
}

inline
size_t Stack::size(void) const
{
    return current_size;
}

inline
bool Stack::empty(void) const
{
    return !current_size;
}

std::ostream &operator<<(std::ostream &stream, const Stack &s);

#endif // __STACK_H__

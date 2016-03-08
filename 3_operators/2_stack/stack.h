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
    Stack(const std::initializer_list<double> &init);
    ~Stack(void);

    void operator=(Stack &&src);
    void operator=(const Stack &src);
    Stack operator+(const Stack &src) const;
    void operator+=(const Stack &src);

    // Stack needs at least l elements
    const double &operator[](size_t l) const;
    double &operator[](size_t l);

    void push(double value);
    void operator+=(double value);
    void pop(void);

    // Stack has to be nonempty
    double &top(void);
    const double &top(void) const;

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
void Stack::operator+=(double value)
{
    push(value);
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

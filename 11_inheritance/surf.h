#ifndef __SURF_H__
#define __SURF_H__

#include <iostream>

struct Surf
{
    virtual double area(void) const = 0;
    virtual double circumference(void) const = 0;
    virtual Surf* clone(void) const & = 0;
    virtual Surf* clone(void) && = 0;
    virtual std::ostream &print(std::ostream &stream) const = 0;

    virtual ~Surf(void);
}; // struct Surf

inline
Surf::~Surf(void)
{
}

#endif // __SURF_H__

#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "surf.h"
#include <cmath>

struct Rectangle: public Surf
{
    double x1, y1;
    double x2, y2;

    Rectangle(double _x1=0, double _y1=0, double _x2=0, double _y2=0);

    double area(void) const override;
    double circumference(void) const override;
    Rectangle* clone(void) const & override;
    Rectangle* clone(void) && override;

    std::ostream &print(std::ostream &stream) const override;
}; // struct Rectangle

inline
Rectangle::Rectangle(double _x1, double _y1, double _x2, double _y2)
:x1(_x1)
,y1(_y1)
,x2(_x2)
,y2(_y2)
{
}

inline
double Rectangle::area(void) const
{
    return std::abs(x1 - x2) * std::abs(y1 - y2);
}

inline
double Rectangle::circumference(void) const
{
    return std::abs(x1 - x2) * 2 + std::abs(y1 - y2) * 2;
}

inline
Rectangle* Rectangle::clone(void) const &
{
    return new Rectangle(*this);
}

inline
Rectangle* Rectangle::clone(void) &&
{
    return new Rectangle(std::move(*this));
}

inline
std::ostream &Rectangle::print(std::ostream &stream) const
{
    return stream << "Rectangle(" << x1 << ", " << y1 << "; " << x2 << ", " << y2 << ")";
}

#endif // __RECTANGLE_H__

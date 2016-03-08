#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "surf.h"
#include <cmath>

struct Circle: public Surf
{
    double x, y;
    double radius;

    Circle(double _x=0, double _y=0, double _radius=0);

    double area(void) const override;
    double circumference(void) const override;
    Circle* clone(void) const & override;
    Circle* clone(void) && override;

    std::ostream &print(std::ostream &stream) const override;
}; // struct Circle

inline
Circle::Circle(double _x, double _y, double _radius)
:x(_x)
,y(_y)
,radius(_radius)
{
}

inline
double Circle::area(void) const
{
    return M_PI * radius * radius;
}

inline
double Circle::circumference(void) const
{
    return 2.0 * M_PI * radius;
}

inline
Circle* Circle::clone(void) const &
{
    return new Circle(*this);
}

inline
Circle* Circle::clone(void) &&
{
    return new Circle(std::move(*this));
}

inline
std::ostream &Circle::print(std::ostream &stream) const
{
    return stream << "Circle(" << x << ", " << y << "; radius=" << radius << ")";
}

#endif // __CIRCLE_H__

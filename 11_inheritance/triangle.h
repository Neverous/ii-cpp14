#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "surf.h"
#include <cmath>

struct Triangle: public Surf
{
    double x1, y1;
    double x2, y2;
    double x3, y3;


    Triangle(double _x1=0, double _y1=0, double _x2=0, double _y2=0, double _x3=0, double _y3=0);

    double area(void) const override;
    double circumference(void) const override;
    Triangle* clone(void) const & override;
    Triangle* clone(void) && override;

    std::ostream &print(std::ostream &stream) const override;
}; // struct Triangle

inline
Triangle::Triangle(double _x1, double _y1, double _x2, double _y2, double _x3, double _y3)
:x1(_x1)
,y1(_y1)
,x2(_x2)
,y2(_y2)
,x3(_x3)
,y3(_y3)
{
}

inline
double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

inline
double Triangle::area(void) const
{
    double a = distance(x1, y1, x2, y2);
    double b = distance(x1, y1, x3, y3);
    double c = distance(x2, y2, x3, y3);
    double s = (a + b + c) / 2.0;

    return sqrt(s * (s - a) * (s - b) * (s - c));

}

inline
double Triangle::circumference(void) const
{
    double a = distance(x1, y1, x2, y2);
    double b = distance(x1, y1, x3, y3);
    double c = distance(x2, y2, x3, y3);

    return a + b + c;
}

inline
Triangle* Triangle::clone(void) const &
{
    return new Triangle(*this);
}

inline
Triangle* Triangle::clone(void) &&
{
    return new Triangle(std::move(*this));
}

inline
std::ostream &Triangle::print(std::ostream &stream) const
{
    return stream << "Triangle(" << x1 << ", " << y1 << "; " << x2 << ", " << y2 << "; " << x3 << ", " << y3 << ")";
}

#endif // __TRIANGLE_H__

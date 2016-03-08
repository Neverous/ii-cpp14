#ifndef __SURFACE_H__
#define __SURFACE_H__

#include "surf.h"
#include <memory>

class Surface
{
    Surf *ref;

public:
    Surface(const Surface &src);
    Surface(Surface &&src);

    Surface(const Surf &src);
    Surface(Surf &&src);

    ~Surface(void);

    void operator=(const Surface &src);
    void operator=(Surface &&src);

    void operator=(const Surf &src);
    void operator=(Surf &&src);

    const Surf *operator->(void) const;
    const Surf &operator*(void) const;
}; // class Surface

inline
std::ostream &operator<<(std::ostream &stream, const Surface &s)
{
    return s->print(stream);
}

inline
Surface::Surface(const Surface &src)
:ref{src.ref->clone()}
{
    std::clog << "CONSTRUCTOR1\n";
}

inline
Surface::Surface(Surface &&src)
:ref{std::move(*src.ref).clone()}
{
    std::clog << "CONSTRUCTOR2\n";
}

inline
Surface::Surface(const Surf &src)
:ref{src.clone()}
{
    std::clog << "CONSTRUCTOR3\n";
}

inline
Surface::Surface(Surf &&src)
:ref{std::move(src).clone()}
{
    std::clog << "CONSTRUCTOR4\n";
}

inline
Surface::~Surface(void)
{
    std::clog << "DESTRUCTOR\n";
    delete ref;
}

inline
void Surface::operator=(const Surface &src)
{
    std::clog << "OPERATOR=1\n";
    *this = Surface(src);
}

inline
void Surface::operator=(Surface &&src)
{
    std::clog << "OPERATOR=2\n";
    std::swap(ref, src.ref);
}

inline
void Surface::operator=(const Surf &src)
{
    std::clog << "OPERATOR=3\n";
    if(&src != ref)
    {
        delete ref;
        ref = src.clone();
    }
}

inline
void Surface::operator=(Surf &&src)
{
    std::clog << "OPERATOR=4\n";
    if(&src != ref)
    {
        delete ref;
        ref = std::move(src).clone();
    }
}

inline
const Surf *Surface::operator->(void) const
{
    return ref;
}

inline
const Surf &Surface::operator*(void) const
{
    return *ref;
}

#endif // __SURFACE_H__

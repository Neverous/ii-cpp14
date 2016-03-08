#include "tree.h"
#include <stdexcept>

tree::tree( const tree& t )
:pntr{t.pntr}
{
    std::cout << "CONSTRUCT_COPY\n";
    ++ pntr->refcnt;
}

void tree::operator = ( tree&& t )
{
    std::cout << "RVALUE_ASSIGN\n";
    std::swap(pntr, t.pntr);
}

void tree::operator = ( const tree& t )
{
    std::cout << "LVALUE_ASSIGN\n";
    (*this) = tree(t);
}

const std::string& tree::functor( ) const
{
    if(!pntr) throw std::runtime_error("Missing tree pointer");
    return pntr->f;
}

std::string& tree::functor( )
{
    if(!pntr) throw std::runtime_error("Missing tree pointer");
    std::cout << "NON-CONST FUNCTOR\n";
    ensure_not_shared();
    return pntr->f;
}

const tree& tree::operator [ ] ( size_t i ) const
{
    if(!pntr) throw std::runtime_error("Missing tree pointer");
    return pntr->subtrees.at(i);
}

tree& tree::operator [ ] ( size_t i )
{
    if(!pntr) throw std::runtime_error("Missing tree pointer");
    std::cout << " NON-CONST op[]\n";
    ensure_not_shared();
    return pntr->subtrees.at(i);
}

size_t tree::nrsubtrees( ) const
{
    if(!pntr) throw std::runtime_error("Missing tree pointer");
    return pntr->subtrees.size();
}

tree::~tree( )
{
    std::cout << "DESTRUCT\n";
    if(!pntr) throw std::runtime_error("Missing tree pointer");
    if(!-- pntr->refcnt)
    {
        std::cout << "DELETE tptr\n";
        delete pntr;
    }
}

bool tree::operator!=(const tree& t) const
{
    return pntr != t.pntr;
}

void tree::ensure_not_shared( )
{
    if(!pntr) throw std::runtime_error("Missing tree pointer");
    if(pntr->refcnt == 1) return;

    std::cout << pntr->f << " SHARED - COPYING\n";
    trnode *new_pntr = new trnode{pntr->f, pntr->subtrees, 1};
    -- pntr->refcnt;
    pntr = new_pntr;

}

std::ostream& operator << ( std::ostream& stream, const tree& t )
{
    stream << t.functor();

    if(!t.nrsubtrees())
        return stream;

    stream << "{";
    for(size_t i = 0; i < t.nrsubtrees(); ++ i)
        stream << " " << t[i];

    return stream << " }";
}

tree subst(const tree& t, const std::string& var, const tree& val)
{
    std::cout << t.functor() << " PRE-IF\n";
    if(!t.nrsubtrees() && t.functor() == var)
        return val;

    std::cout << t.functor() << " POST-IF\n";

    tree n = t;
    for(size_t i = 0; i < t.nrsubtrees(); ++ i)
    {
        tree temp = subst(t[i], var, val);
        if(temp != t[i])
            n[i] = temp;
    }

    return n;
}

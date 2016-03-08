
#include "varchain.h"
#include <algorithm>
#include "utils.h"

varchain operator * ( varchain c1, const varchain& c2 )
{
    c1.repr.reserve(c1.repr.size() + c2.repr.size());
    c1.repr.insert(end(c1.repr), begin(c2.repr), end(c2.repr));
    c1.normalize();
    return c1;
}

std::ostream& operator << ( std::ostream& out, const powvar & p )
{
   if( p.n == 0 )
   {
      out << "1"; // Should not happen, but we still have to print something.
      return out;
   }

   out << p.v;
   if( p.n == 1 )
      return out;

   if( p.n > 0 )
      out << "^" << p.n;
   else
      out << "^{" << p.n << "}";
   return out;
}


std::ostream& operator << ( std::ostream& out, const varchain& c )
{
   if( c. isunit( ))
   {
      out << "1";
      return out;
   }

   for( auto p = c. repr. begin( ); p != c. repr. end( ); ++ p )
   {
      if( p != c. repr. begin( ))
         out << ".";
      out << *p;
   }

   return out;
}


int varchain::power( ) const
{
   int p = 0;
   for( auto pv : repr )
      p += pv. n;
   return p;
}



void varchain::normalize()
{
    auto powvar_seq = [](const powvar &a, const powvar &b)
    {
        return a.v == b.v;
    };

    std::sort(begin(repr), end(repr));
    repr.erase(join_equal(begin(repr), end(repr), [](powvar &dest, const powvar &from){dest.n += from.n;}, powvar_seq), end(repr));
    repr.erase(std::remove_if(begin(repr), end(repr), [](const powvar &a){return a.n == 0 || a.v == "";}), end(repr));
}

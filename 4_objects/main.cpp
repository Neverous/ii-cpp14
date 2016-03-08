#include "tree.h"


int main( int argc, char* argv [ ] )
{
   tree t1( std::string( "a" ));
   tree t2( std::string( "b" ));
   tree t3 = tree( std::string( "f" ), { t1, t2 } );

   std::vector< tree > arguments = { t1, t2, t3 };
   std::cout << tree( "F", std::move( arguments )) << "\n";

   t2 = t3;
   t2 = std::move(t3);

   for(size_t t = 0; t < 1; ++ t)
   {
       std::cout << "##########PRE\n";
       tree st1 = tree{"st1"};
       tree st11 = st1;
       tree st2 = tree{"st2"};
       tree st21 = st2;
       tree st3 = tree{"st3", {{"HI"}, {"BYE"}, {"CYA"}, {"ONE MORE"}}};
       tree st31 = st3;

       tree tx = tree{"t1", {st1, st2, st3}};
       tree tx1 = tx;
       std::cout << "1 " << tx << "\n";

       st1 = tree{"st4"};
       std::cout << "2 " << tx << "\n";
       tx = subst(tx, "st2", tree{"val"});

       std::cout << "3 " << tx << "\n";

       tx[0] = tree{"hi"};
       std::cout << "4 " << tx << "\n";

       std::cout << "5 " << st3 << "\n";
       tx[2][0] = tree{"hi"};
       std::cout << "6 " << tx << "\n";
       std::cout << "7 " << st3 << "\n";

       if(tx.nrsubtrees() != 3)
           std::cout << "ERR\n";

       std::cout << "##########POST\n";
   }
}

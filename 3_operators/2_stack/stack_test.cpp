#include <iostream>

#include "stack.h"

int main(void)
{
    for(unsigned int i = 0; i < 1024; ++ i)
    {
        Stack s1;
        s1.push(45); s1.push(45); s1.push(46);

        //std::cout << " ===== INIT ===== " << std::endl;
        //std::cout << "s1: " << s1 << std::endl;
        Stack s2 = s1;

        for(unsigned int j = 0; j < 20; ++ j)
            s2.push(j * j);

        //std::cout << "s2: " << s2 << std::endl;
        s1 = s2;
        s1 = s1;

        //std::cout << " ===== ASSIGN ===== " << std::endl;
        //std::cout << "s1: " << s1 << std::endl;
        //std::cout << "s2: " << s2 << std::endl;
        Stack &sconst = s1;
        sconst.top() = 20;
        sconst.push(15);

        //std::cout << " ===== REFERENCE ===== " << std::endl;
        //std::cout << "s1: " << s1 << std::endl;
        //std::cout << "s2: " << s2 << std::endl;
        //std::cout << "sc: " << sconst << std::endl;

        //std::cout << " ===== RESET ===== " << std::endl;
        sconst.reset(5);
        //std::cout << "s1: " << s1 << std::endl;
        //std::cout << "s2: " << s2 << std::endl;
        //std::cout << "sc: " << sconst << std::endl;

        //std::cout << " ===== POP ===== " << std::endl;
        //std::cout << "s2.top: " << s2.top() << std::endl;
        s2.pop();
        //std::cout << "s2: " << s2 << std::endl;

        //std::cout << std::endl;

        Stack s3 = s1 + s2;
        s1 += s2;

        double test = s3[0];
        double val = 5.5l;
        s3 += val;
        if(s3[0] != val || s3[1] != test)
            std::cout << "ERROR" << std::endl;

        Stack s4{1.0l, 2.0l, 7.0l};
        if(s4[0] != 7.0l || s4[1] != 2.0l || s4[2] != 1.0l)
            std::cout << "ERROR" << std::endl;

        s4 += s4;
    }

    return 0;
}


#ifndef __RAII__
#define __RAII__

#include "indent.h"

#include <iostream>

struct Raii
{
    Raii()                   { std::cout << +i << "Raii()\n"; }
    Raii(const int a) : a(a) { std::cout << +i << "Raii() " << a << "\n"; }
    ~Raii()                  { std::cout << -i << "~Raii() " << a << "\n"; if (a > 0) std::cout << "\n"; }

    int a = -1;
    Indent i;
};

#endif

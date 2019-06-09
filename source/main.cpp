
#include "size.h"

#include <array>
#include <iostream>

int main()
{
    const std::array<int, 3_elements> a = {1, 2, 3};

    std::cout << "size = " << a.size() << "\n";
    std::cout << "second element = " << a[1u] << "\n";

    return 0;
}


#include "size.h"

constexpr unsigned int operator ""_elements(const unsigned long long n)
{
    return static_cast<int>(n);
}

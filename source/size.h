
#ifndef __SIZE_H__
#define __SIZE_H__

constexpr unsigned int operator""_elements(const unsigned long long n)
{
    return static_cast<unsigned int>(n);
}

#endif

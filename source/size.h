
#ifndef __SIZE_H__
#define __SIZE_H__

struct Size
{
    Size(const unsigned int n) : s(n) {}

    const unsigned int s;
};

constexpr Size operator""_elements(const unsigned long long n)
{
    return static_cast<unsigned int>(n);
}

#endif

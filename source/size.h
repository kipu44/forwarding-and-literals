
#ifndef __SIZE_H__
#define __SIZE_H__

struct Size
{
    constexpr Size(const unsigned int n) : s(n) {}

    constexpr operator unsigned int() { return s; }

    const unsigned int s;
};

constexpr Size operator""_elements(const unsigned long long n)
{
    return static_cast<unsigned int>(n);
}

#endif

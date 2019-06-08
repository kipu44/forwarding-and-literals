
#ifndef __INDENT__
#define __INDENT__

#include <string>

struct Indent
{
    Indent() : s((i += n) - n) {}
    ~Indent() { i = s; }

    auto operator-() const { return std::string(s + 0, ' '); }
    auto operator+() const { return std::string(s + 1, ' '); }

    private: Indent(const int s) : s(s) { i += n; }
    public: const int s;

    static int i;
    static int n;
};

#endif

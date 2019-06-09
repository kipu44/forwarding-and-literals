
#ifndef __FOO_BAR__
#define __FOO_BAR__

#include "indent.h"

#include <iostream>
#include <string>

int n();

struct Counter
{
    template <typename T>
    Counter(T && s) noexcept : s(std::forward<T>(s)) {}
    ~Counter() { std::cout << s << " " << i << "\n"; }

    std::string s;
    int i = 0;
};

struct Foo
{
    Foo()                               { std::cout << +i << "Foo() "  << a << " default-constructed" << "\n"; }
    ~Foo()                              { std::cout << -i << "~Foo() " << a << " " << s << "\n";                         s = "destroyed"; }
    Foo(Foo && foo) : a(foo.a + 1)      { std::cout << +i << "Foo() "  << a << " move-constructed from " << foo << "\n"; foo.s = "moved"; ++move.i; }
    Foo(const Foo & foo) : a(foo.a + 1) { std::cout << +i << "Foo() "  << a << " copy-constructed from " << foo << "\n";                  ++copy.i; }

    const int a = n();
    std::string s;
    Indent i;

    static Counter move;
    static Counter copy;

    friend std::ostream & operator<<(std::ostream & stream, const Foo & foo);
};

struct Bar
{
    Bar(Foo && foo) : f(std::move(foo))   { std::cout << +i << "Bar(Foo && foo) " << f.a << "\n";      f.s = "inside Bar"; }
    Bar(const Foo & foo) : f(foo)         { std::cout << +i << "Bar(const Foo & foo) " << f.a << "\n"; f.s = "inside Bar"; }
    ~Bar()                                { std::cout << -i << "~Bar() " << f.a << "\n"; }
    Bar(Bar && bar) : f(std::move(bar.f)) { std::cout << +i << "Bar(Bar && bar) " << f.a << "\n"; }
    Bar(const Bar & bar) : f(bar.f)       { std::cout << +i << "Bar(const Bar & bar) " << f.a << "\n"; }

    Foo f;
    Indent i;
};

#endif

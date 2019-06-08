
#ifndef __FOO_BAR__
#define __FOO_BAR__

#include "indent.h"

#include <iostream>

int n()
{
    static int c = 0;
    return c += 10;
}

struct Foo
{
    Foo()                               { std::cout << +i << "Foo() " << a << "\n";                s = "default-constructed";}
    ~Foo()                              { std::cout << -i << "~Foo() " << a << " " << s << "\n";   s = "destroyed"; }
    Foo(Foo && foo) : a(foo.a + 1)      { std::cout << +i << "Foo("/*"Foo && foo"*/") " << a << " move-constructed from " << std::to_string(foo.a) << "\n";      foo.s = "moved"; }
    Foo(const Foo & foo) : a(foo.a + 1) { std::cout << +i << "Foo("/*"const Foo & foo"*/") " << a << " copy-constructed from " << std::to_string(foo.a) << "\n"; }

    const int a = n();
    std::string s;
    Indent i;
};

struct Bar
{
    Bar(Foo && foo) : f(std::move(foo))   { std::cout << +i << "Bar(Foo && foo) " << f.a << "\n";      f.s += ", inside Bar"; }
    Bar(const Foo & foo) : f(foo)         { std::cout << +i << "Bar(const Foo & foo) " << f.a << "\n"; f.s += ", inside Bar"; }
    ~Bar()                                { std::cout << -i << "~Bar() " << f.a << "\n"; }
    Bar(Bar && bar) : f(std::move(bar.f)) { std::cout << +i << "Bar(Bar && bar) " << f.a << "\n"; }
    Bar(const Bar & bar) : f(bar.f)       { std::cout << +i << "Bar(const Bar & bar) " << f.a << "\n"; }

    Foo f;
    Indent i;
};

#endif

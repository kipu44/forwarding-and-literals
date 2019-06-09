
#ifndef __FOO_BAR_H__
#define __FOO_BAR_H__

#include "counter.h"
#include "indent.h"

#include <iostream>
#include <string>

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
    static Counter stats;

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

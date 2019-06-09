
#include "foo-bar.h"
#include "raii.h"

#include <memory>

// #define makeUnique std::make_unique

#ifndef makeUnique
template <typename T>
auto makeUnique = [](auto && ... arg)
{
    const Raii r0{0};
    return std::unique_ptr<T>(new T(std::forward<decltype(arg)>(arg)...));
};
#endif

int main()
{
    {
        const Raii r1{1};

        const auto b1 = makeUnique<Bar>(Bar{Foo{}});
    }
    {
        const Raii r2{2};

        const auto b2 = makeUnique<Bar>(Foo{});
    }
    {
        const Raii r3{3};

        const auto f3 = makeUnique<Foo>();
    }
    {
        const Raii r4{4};

        const auto p4 = makeUnique<std::pair<Foo, Bar>>(Foo{}, Foo{});
    }
    return 0;
}

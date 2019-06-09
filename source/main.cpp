
#include "foo-bar.h"
#include "raii.h"

#include <memory>

// #define makeUnique std::make_unique

#ifndef makeUnique
template <typename T, typename Arg>
auto makeUnique(Arg && arg)
{
    const Raii r0{0};
    return T(std::forward<Arg>(arg));
}
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
    return 0;
}

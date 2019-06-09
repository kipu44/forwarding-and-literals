
#include "foo-bar.h"
#include "raii.h"

#include <memory>

// #define makeUnique std::make_unique

#ifndef makeUnique
template <typename T>
auto makeUnique(T arg)
{
    const Raii r0{0};
    return T(arg);
}
#endif

int main()
{
    {
        const Raii r1{1};

        const auto b1 = makeUnique<Bar>(Bar{Foo{}});
    }
    return 0;
}

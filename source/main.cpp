
#include "foo-bar.h"
#include "indent.h"
#include "raii.h"

#include <memory>

// template <typename T>
// auto makeUnique(T && t)
// {
//     const Raii r0{0};
//     return std::make_unique<T>(std::forward<T>(t));
// }

// template <typename T, typename A>
// auto makeUnique(A && a)
// {
//     const Raii r0{0};
//     return std::make_unique<T>(std::forward<A>(a));
// }

// template<typename T, typename ... Args>
// auto makeUnique(Args && ... args)
// {
//     const Raii r0{0};
//     return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
// }

// #define makeUnique std::make_unique

template<typename T, typename ... Args>
auto makeUnique(Args && ... args)
{
    const Raii r0{0};
    return std::unique_ptr<T>(new T(args...));
}

int main()
{
    {
        const Raii r1{9};

        Bar b1(Foo{});
        const Bar b2(std::move(b1));
    }
    {
        const Raii r1{1};

        const auto b1 = makeUnique<Bar>(Foo{});
    }
    {
        const Raii r2{2};

        Foo f2;
        const auto b2 = makeUnique<Bar>(std::move(f2));
    }
    {
        const Raii r3{3};

        const Foo f3;
        const auto b3 = makeUnique<Bar>(f3);
    }
    return 0;
}

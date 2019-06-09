
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
//     return std::unique_ptr<T>(new T(args...));
// }

// template<typename T, typename ... Args>
// auto makeUnique(Args && ... args)
// {
//     const Raii r0{0};
//     return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
// }

#define makeUnique std::make_unique

// template<typename T>
// auto makeUnique = [](auto && ... args)
// {
//     const Raii r0{0};
//     return std::unique_ptr<T>(new T(args...));
// };

// template<typename T>
// auto makeUnique = [](auto && ... args)
// {
//     const Raii r0{0};
//     return std::unique_ptr<T>(new T(std::forward<decltype(args)>(args)...));
// };

// template<typename T>
// auto makeUnique = [](auto && ... args)
// {
//     const Raii r0{0};
//     return T(std::forward<decltype(args)>(args)...);
// };

// template<typename T>
// auto makeUnique = [](auto && ... args)
// {
//     const Raii r0{0};
//     return T(args...);
// };

// template<typename T>
// auto makeUnique = [](auto ... args)
// {
//     const Raii r0{0};
//     return T(args...);
// };

// template<typename T>
// auto makeUnique = [](auto args)
// {
//     const Raii r0{0};
//     return T(args);
// };

int main()
{
    {
        const Raii r1{1};

        const auto b1 = makeUnique<Bar>(Foo{});
    }
    {
        const Raii r2{2};

        const auto b2 = makeUnique<Bar>(Bar{Foo{}});
    }
    {
        const Raii r3{3};

        const auto f3 = makeUnique<Foo>();
    }
    {
        const Raii r4{4};

        const auto p4 = makeUnique<std::pair<Foo, Bar>>(Foo{}, Bar{Foo{}});
    }
    return 0;
}


#include "foo-bar.h"

Counter Foo::move("move");
Counter Foo::copy("copy");
Counter Foo::stats("statistics for Foo:");

std::ostream & operator<<(std::ostream & stream, const Foo & foo)
{
    return stream << std::to_string(foo.a);
}

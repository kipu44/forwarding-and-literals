
#include "foo-bar.h"

int n()
{
    static int c = 0;
    return c += 10;
}

Counter Foo::move("move");
Counter Foo::copy("copy");

std::ostream & operator<<(std::ostream & stream, const Foo & foo)
{
    return stream << std::to_string(foo.a);
}

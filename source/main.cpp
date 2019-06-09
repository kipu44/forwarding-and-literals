
#include "foo-bar.h"
#include "indent.h"
#include "raii.h"

int main()
{
    Indent::i = 2;
    Indent::n = 0;

    const Raii r(9);

    Bar b1(Foo{});
    const Bar b2(std::move(b1));

    return 0;
}

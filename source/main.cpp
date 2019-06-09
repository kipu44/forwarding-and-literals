
#include <iostream>
#include <string>
#include <type_traits>

int main()
{
    std::cout << std::boolalpha;

    const auto hello = "hello";

    std::cout << std::is_same<std::decay_t<decltype(hello)>, std::string>::value << "\n";

    return 0;
}

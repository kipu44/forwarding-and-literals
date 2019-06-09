
#include <iostream>
#include <string>
#include <type_traits>

int main()
{
    std::cout << std::boolalpha;
    using namespace std::string_literals;

    const auto hello = "hello"s; // ""s <- C++14

    std::cout << std::is_same<std::decay_t<decltype(hello)>, std::string>::value << "\n";

    return 0;
}

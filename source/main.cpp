
#include <array>
#include <iostream>

constexpr unsigned int operator""_elements(const unsigned long long n)
{
    return static_cast<int>(n);
}

int main()
{
    const std::array<int, 3_elements> a = {1, 2, 3};

    std::cout << "size = " << a.size() << "\n";
    std::cout << "second element = " << a[1u] << "\n";

    return 0;
}

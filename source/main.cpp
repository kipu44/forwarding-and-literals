
#include <iostream>
#include <vector>

unsigned int operator""_elements(const unsigned long long n)
{
    return static_cast<int>(n);
}

int main()
{
    const std::vector<int> a(3_elements, 1);

    std::cout << "size = " << a.size() << "\n";
    std::cout << "second element = " << a[1u] << "\n";

    return 0;
}

#include <fmt/core.h>
#include <iostream>
#include "String.hpp"

using namespace my;

auto main() -> int
{
    String str{" Test"};

    std::cout << "Using iterator: \n";

    for (auto it = str.begin(); it < str.end(); ++it)
    {
        std::cout << *it;
    }

    String name{"Jarek"};
    std::cout << "\nsize : " << name.size() << " capacity: " << name.capacity() << '\n';

    name += str;

    fmt::print("Hello {}", name);

    std::cout << '\n';

    String reverseTest{"jarek  esrever"};
    for (auto it = reverseTest.rbegin(); it < reverseTest.rend(); ++it)
    {
        std::cout << *it;
    }
}
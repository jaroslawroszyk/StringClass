#include <fmt/core.h>
#include <iostream>
#include "String.hpp"

using namespace my;

auto main() -> int
{
    //    String str{" Test"};
    //
    //    std::cout << "Using iterator: \n";
    //
    //    for (auto it = str.begin(); it < str.end(); ++it)
    //    {
    //        std::cout << *it;
    //    }
    //
    //    char buffer[20];
    //    std::size_t length = str.copy(buffer, 6, 5);
    //    buffer[length] = '\0';
    //    std::cout << "buffer contains: " << buffer << '\n';
    //
    //    String name{"Jarek"};
    //    swap(str, name);
    //    std::cout << str;
    //    swap(name, str);
    //    std::cout << name;
    //    std::cout << "\nsize : " << name.size() << " capacity: " << name.capacity() << '\n';
    //
    //    name += str;
    //
    //    fmt::print("Hello {}", name);
    //
    //    std::cout << '\n';
    //
    //    String reverseTest{"jarek  esrever"};
    //    for (auto it = reverseTest.rbegin(); it < reverseTest.rend(); ++it)
    //    {
    //        std::cout << *it;
    //    }
    String s{"This Is An Example"};

    s.erase(7, 3); // erases " An" using overload (1)
    fmt::print("s = {}, s.size = {} , s.capacity = {}", s, s.size(), s.capacity());
}
#include <fmt/core.h>
#include <iostream>
#include "String.hpp"

using namespace my;
auto main() -> int
{
    String name{"Jarek"};
    std::cout << "size : " << name.size() << " capacity: " << name.capacity() << '\n';
    String str{" Dev "};
    name += str;
    fmt::print("Hello {}", name);
}
//add loger from githubj
#include "String.hpp"

namespace my
{
void swap(String& lhs, String& rhs)
{
    lhs.swap(rhs);
}

bool operator == (const String & lhs, const String & rhs)
{
    return lhs.compare(rhs) == 0;
}

//template<typename T>
//bool String::operator==(const T&lhs, const T&rhs)
//{
//    return lhs.com
//}
std::ostream& operator<<(std::ostream& os, const String& str)
{
    for (size_t i = 0; i < str.length(); ++i)
        os << str[i];
    return os;
}

std::istream& operator>> (std::istream& is, String& str)
{
    for (size_t i = 0; i < str.length(); ++i)
        is >> str[i];
    return is;
}

} // namespace my
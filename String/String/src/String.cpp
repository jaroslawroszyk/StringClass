#include "String.hpp"
#include <ostream>

namespace my
{
String::String() = default;

String::String(char ch)
{
    internal_assign(&ch, 1);
}

String::String(const char* str)
{
    internal_assign(str, std::strlen(str));
}

String::String(const String& rhs)
{
    internal_assign(rhs.m_data.get(), rhs.m_size);
}

String::String(String&& rhs)
{
    *this = std::move(rhs);
}

String::String(const String& s, size_type pos, size_type n)
{
    internal_assign(s.m_data.get(), n, pos);
}

String::String(const char* cs, size_type n)
{
    internal_assign(cs, n);
}

String::String(size_type n, const char& c)
{
    reserve(n);
    for (size_type i = 0; i < n; i++)
        m_data.get()[i] = c;
    m_data.get()[n] = '\0';
    m_size = n;
}

// Operators
String String::operator+(const String& str)
{
    String lhs(*this);
    lhs += str;
    return lhs;
}
} // namespace my
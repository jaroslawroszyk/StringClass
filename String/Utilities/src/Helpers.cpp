#include "String.hpp"

namespace my
{
inline void String::_append(const char* other)
{
    _append(other, strlen(other));
}

void String::_append(const char* other, size_type n)
{
    if (!other || n == 0) // if other is null or size is 0 do nothing
        return;
    increaseCapacity(m_size + n);
    size_type i = 0;
    for (; i < n; ++i)
        operator[](m_size + i) = other[i];
    operator[](m_size + i) = '\0';
    setLength(m_size + n);
}

void String::_erase(size_type pos, size_type n)
{
    n = getLength(*this, pos, n);
    for (size_type i = pos + n; i < m_size; ++i)
    {
        operator[](i - n) = operator[](i);
    }
    clear_str(m_size - n);
}

void String::fill_str(char* other, const size_type len, const size_type pos, char c)
{
    size_type begin = pos;
    while (begin != len)
        other[begin++] = c;
    other[begin] = '\0';
}

void String::clear_str(const size_type pos)
{
    fill_str(m_data.get(), m_size, pos, '\0');
    m_size = pos;
}
} // namespace my
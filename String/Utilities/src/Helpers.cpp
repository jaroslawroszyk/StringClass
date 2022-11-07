#include "String.hpp"

namespace my
{
inline void String::_append(const char * other)
{
    _append(other,strlen(other));
}

void String::_append(const char * other, size_t n)
{
    if (!other || n == 0) // if other is null or size is 0 do nothing
        return;
    increaseCapacity(m_size + n);
    size_t i = 0;
    for (; i < n; ++i)
        operator[](m_size + i) = other[i];
    operator[](m_size + i) = '\0';
    setLength(m_size + n);
}

void String::_erase(std::size_t pos, std::size_t n)
{
    n = getLength(*this,pos,n);
    for(size_t i = pos + n; i < m_size; ++i)
    {
        operator[](i-n) = operator[](i);
    }
    clear_str(m_size-n);
}

void String::fill_str(char * other, const size_t len, const size_t pos, char c)
{
    std::size_t begin = pos;
    while (begin != len)
        other[begin++] = c;
    other[begin] = '\0';
}

void String::clear_str(const size_t pos)
{
    fill_str(m_data.get(),m_size,pos,'\0');
    m_size = pos;
}
} // namespace my
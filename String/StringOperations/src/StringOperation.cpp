#include "String.hpp"

namespace my
{
std::size_t String::copy(char* s, std::size_t len, std::size_t pos) // properly?
{
    if (!s) throw;

    len = m_size;

    for (std::size_t i = 0; i < m_size - 1; ++i)
    {
        *(s + i) = operator[](pos + i);
    }
    m_data[m_size] = '\0';
    return len;
}

void String::swap(String& other)
{
    String temp = std::move(*this);
    *this = std::move(other);
    other = std::move(temp);
}

String& String::erase(size_t pos, size_t len)
{
    _erase(pos, len);
    return *this;
}

void String::clear()
{
    clear_str(0);
}

template<typename T>
String& String::operator+=(const T& t)
{
    return *this += String(t);
}

String& String::push_back(char ch)
{
    _append(&ch,1);
    return *this;
}

int String::compare(const String& rhs) const
{
    if(m_size < rhs.m_size) return 1;
    else if(m_size > rhs.m_size) return -1;
    return strcmp(m_data.get(),rhs.m_data.get());
}

String& String::operator+=(const String& str)
{
    size_t new_size = m_size + str.m_size;

    reserve(new_size);

    memcpy(
        m_data.get() + m_size,
        str.m_data.get(),
        str.m_size + 1);
    m_size = new_size;
    return *this;
}
} // namespace my
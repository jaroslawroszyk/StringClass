#include "String.hpp"

namespace my
{
std::size_t String::copy(char* s, std::size_t len, std::size_t pos) const
{
    if (!s) throw;
    if (pos > size()) throw std::out_of_range("out of range");

    len = m_size;

    for (std::size_t i = 0; i < m_size - 1; ++i)
    {
        *(s + i) = operator[](pos + i);
    }
    m_data[m_size] = '\0';
    return len;
}

void String::swap(String& other) noexcept
{
    String temp = std::move(*this);
    *this = std::move(other);
    other = std::move(temp);
}

String& String::erase(size_t index, size_t count)
{
    if (index > size()) throw std::out_of_range("out_of_range");
    _erase(index, count);
    return *this;
}

void String::clear() noexcept
{
    clear_str(0);
}

template <typename T>
String& String::operator+=(const T& t)
{
    return *this += String(t);
}

String& String::push_back(char ch)
{
    if (size() > max_size()) throw std::length_error("length_error");
    _append(&ch, 1);
    return *this;
}

int String::compare(const String& rhs) const noexcept
{
    if (m_size < rhs.m_size)
        return 1;
    else if (m_size > rhs.m_size)
        return -1;
    return strcmp(m_data.get(), rhs.m_data.get());
}

String& String::operator+=(const String& str)
{
    if (size() > max_size()) throw std::length_error("length_error");
    size_t new_size = m_size + str.m_size;

    reserve(new_size);

    memcpy(m_data.get() + m_size, str.m_data.get(), str.m_size + 1);
    m_size = new_size;
    return *this;
}
} // namespace my
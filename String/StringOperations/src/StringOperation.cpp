#include "String.hpp"

namespace my
{
String::size_type String::copy(char* s, size_type len, size_type pos) const
{
    if (!s) throw;
    if (pos > size()) throw std::out_of_range("out of range");

    len = m_size;

    for (size_type i = 0; i < m_size - 1; ++i)
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

String& String::erase(size_type index, size_type count)
{
    // ver1
    if (index > size()) throw std::out_of_range("out_of_range");
    size_type new_size = m_size - count;
    memmove(&m_data[index], &m_data[index + count], m_size - index - count);
    m_data[new_size] = '\0';
    m_size = new_size;
    // ver2
    //    _erase(index, count); //todo: this is needed?
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
    size_type new_size = m_size + str.m_size;

    reserve(new_size);

    memcpy(m_data.get() + m_size, str.m_data.get(), str.m_size + 1);
    m_size = new_size;
    return *this;
}

void String::insert(size_type index, const char* s)
{
    if (index > m_size) throw std::out_of_range("out of range");
    size_type sizeChar = strlen(s);
    size_type new_size = m_size + sizeChar;
    reserve(new_size);
    memmove(&m_data.get()[index + sizeChar], &m_data.get()[index], m_size - index);
    memcpy(&m_data.get()[index], s, sizeChar);
    m_data[new_size] = '\0';
    m_size = new_size;
}

void String::insert(size_type index, const String& val)
{
    if (index > m_size) throw std::out_of_range("out of range");
    size_type new_size = m_size + val.m_size;
    reserve(new_size);
    memmove(&m_data.get()[index + val.m_size], &m_data.get()[index], m_size - index);
    memcpy(&m_data.get()[index], val.m_data.get(), val.m_size);
    m_data[new_size] = '\0';
    m_size = new_size;
}
} // namespace my
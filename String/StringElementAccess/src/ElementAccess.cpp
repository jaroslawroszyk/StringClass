#include "String.hpp"

namespace my
{
char& String::at(std::size_t pos)
{
    if (pos > m_size) throw std::out_of_range("out_of_range");
    return m_data.get()[pos];
}

const char& String::at(std::size_t pos) const
{
    if (pos > m_size) throw std::out_of_range("out_of_range");
    return m_data.get()[pos];
}

char& String::operator[](std::size_t idx)
{
    return m_data.get()[idx];
}

char& String::operator[](std::size_t idx) const
{
    return m_data.get()[idx];
}

char& String::front()
{
    return operator[](0);
}

const char& String::front() const
{
    return operator[](0);
}

char& String::back()
{
    return operator[](m_size - 1);
}

const char& String::back() const
{
    return operator[](m_size - 1);
}

const char* String::data() const
{
    return m_data.get();
}

const char* String::c_str() const
{
    return m_data.get();
}
} // namespace my
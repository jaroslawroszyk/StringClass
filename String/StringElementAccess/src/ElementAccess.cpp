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

char& String::operator[](std::size_t pos)
{
    return m_data.get()[pos];
}

char& String::operator[](std::size_t pos) const
{
    return m_data.get()[pos];
}

char& String::front()
{
    if(empty() == true) throw "undefined behavior";
    return operator[](0);
}

const char& String::front() const
{
    if(empty() == true) throw "undefined behavior";
    return operator[](0);
}

char& String::back()
{
    if(empty() == true) throw "undefined behavior";
    return operator[](m_size - 1);
}

const char& String::back() const
{
    if(empty() == true) throw "undefined behavior";
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
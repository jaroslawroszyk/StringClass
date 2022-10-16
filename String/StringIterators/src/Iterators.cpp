#include "String.hpp"

namespace my
{
String::iterator String::begin() noexcept 
{
    return m_data.get();
}

String::const_iterator String::begin() const noexcept
{
    return cbegin();
}

String::const_iterator String::cbegin() const noexcept
{
    return m_data.get();
}

String::iterator String::end() noexcept
{
    return m_data.get() + m_size;
}

String::const_iterator String::end() const noexcept
{
    return cend();
};

String::const_iterator String::cend() const noexcept
{
    return m_data.get() + m_size;
}

String::reverse_iterator String::rbegin() noexcept
{
    return std::reverse_iterator(end());
}

String::const_reverse_iterator String::rbegin() const noexcept
{
   return std::reverse_iterator(cend()); 
}

String::const_reverse_iterator String::crbegin() const noexcept
{
    return std::reverse_iterator(end());
}

String::reverse_iterator String::rend() noexcept
{
    return std::reverse_iterator(begin());
}

String::const_reverse_iterator String::rend() const noexcept
{
    return std::reverse_iterator(cbegin());
}

String::const_reverse_iterator String::crend() const noexcept
{
    return std::reverse_iterator(begin());
}
} // namespace my
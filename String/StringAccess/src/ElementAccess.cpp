#include "String.hpp"

namespace my
{
    char &String::at(std::size_t pos)
    {
        if (pos > m_size) throw std::out_of_range("out_of_range");
        return m_data.get()[pos];
    }

    const char &String::at(std::size_t pos) const
    {
        if (pos > m_size) throw std::out_of_range("out_of_range");
        return m_data.get()[pos];
    }

    const char *String::data() const
    {
        return m_data.get();
    }

    const char *String::c_str() const
    {
        return m_data.get();
    }
}
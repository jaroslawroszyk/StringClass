#include "String.hpp"

namespace my
{
bool String::empty() const
{
    return m_size ? false : true;
}

String::String::size_type String::length() const noexcept
{
    return m_size;
}

String::size_type String::size() const noexcept
{
    return m_size;
}

String::size_type String::max_size() const noexcept
{
    return String::npos - 1;
}

String::size_type String::capacity() const noexcept
{
    return m_capacity;
}

void String::shrink_to_fit()
{
    decreaseCapacity(m_size);
}

void String::reserve(size_type new_cap)
{
    if (m_capacity < new_cap)
    {
        auto oldData = std::move(m_data);
        allocateMemory(new_cap);
        if (oldData)
        {
            memcpy(m_data.get(), oldData.get(), m_size + 1);
        }
        m_capacity = new_cap;
    }
}
}
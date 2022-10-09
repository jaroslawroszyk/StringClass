#include "String.hpp"

namespace my
{
std::size_t String::length() const noexcept
{
    return m_size;
}

std::size_t String::size() const noexcept
{
    return m_size;
}

std::size_t String::capacity() const noexcept
{
    return m_capacity;
}

void String::reserve(size_t new_size)
{
    if (m_capacity < new_size)
    {
        auto oldData = std::move(m_data);
        allocateMemory(new_size);
        if (oldData)
        {
            memcpy(m_data.get(), oldData.get(), m_size + 1);
        }
        m_capacity = new_size;
    }
}
// todo: shrink_to_fit
}
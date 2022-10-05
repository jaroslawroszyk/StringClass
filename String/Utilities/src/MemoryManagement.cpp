#include "String.hpp"

namespace my
{
void String::internal_assign(const char* str, std::size_t n, std::size_t pos)
{
    size_t new_size = n;

    allocateMemory(new_size);

    memcpy(m_data.get(), str + pos, new_size);
    m_data[new_size] = '\0';
    m_size = new_size;
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

void String::allocateMemory(size_t new_size)
{
    if (m_capacity < new_size)
    {
        m_data = std::make_unique<char[]>(new_size + 1);
        m_capacity = new_size;
    }
}
} // namespace my
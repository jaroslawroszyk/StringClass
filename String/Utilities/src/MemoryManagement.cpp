#include "String.hpp"

namespace my
{
void String::internal_assign(const char* str, size_type n, size_type pos)
{
    size_type new_size = n;

    allocateMemory(new_size);

    memcpy(m_data.get(), str + pos, new_size);
    m_data[new_size] = '\0';
    m_size = new_size;
}

void String::allocateMemory(size_type new_size)
{
    if (m_capacity < new_size)
    {
        m_data = std::make_unique<char[]>(new_size + 1);
        m_capacity = new_size;
    }
}

void String::increaseCapacity(const size_type n)
{
    if (m_capacity > n && m_data) return;
    // Increase Capacity Calculation
    size_type cap = m_capacity;
    while (cap <= n)
        cap += m_increaseBy;
    m_increaseBy++;

    reserve(cap); // increase Capacity
}

void String::decreaseCapacity(const size_type cap)
{
    if (m_capacity < cap) return;
    if (m_increaseBy > 15) --m_increaseBy;
    allocateMemory(cap);
}

void String::setLength(const size_type len)
{
    if (m_size > len)
        clear_str(len);
    else if (m_capacity < len)
        increaseCapacity(len);
    m_size = len;
}

String::size_type String::getLength(const String& str, size_type pos, size_type len) const
{
    if (len == npos) len = m_size - pos;

    if (pos + len > str.m_size)
    {
        throw;
    }
    return len;
}
} // namespace my
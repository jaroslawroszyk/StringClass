#include "String.hpp"
#include <ostream>

namespace my
{
String::String() = default;

String::String(char ch)
{
    internal_assign(&ch, 1);
}

String::String(const char* str)
{
    internal_assign(str, std::strlen(str));
}

String::String(const String& rhs)
{
    internal_assign(rhs.m_data.get(), rhs.m_size);
}

String::String(String&& rhs)
{
    *this = std::move(rhs);
}

String::String(const String& s, size_t pos, size_t n)
{
    internal_assign(s.m_data.get(), n, pos);
}

String::String(const char* cs, size_t n)
{
    internal_assign(cs, n);
}

String::String(size_t n, const char& c)
{
    reserve(n);
    for (size_t i = 0; i < n; i++)
        m_data.get()[i] = c;
    m_data.get()[n] = '\0';
    m_size = n;
}

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

// Operators
String& String::operator=(const String& str)
{
    if (this == &str) return *this;
    internal_assign(str.m_data.get(), str.m_size);
    return *this;
}

String& String::operator=(String&& str)
{
    if (this == &str) return *this;
    std::swap(m_data, str.m_data);
    std::swap(m_size, str.m_size);
    std::swap(m_capacity, str.m_capacity);
    return *this;
}

String& String::operator+=(const String& str)
{
    size_t new_size = m_size + str.m_size;

    reserve(new_size);

    memcpy(
        m_data.get() + m_size,
        str.m_data.get(),
        str.m_size + 1);
    m_size = new_size;
    return *this;
}

template<typename T>
String& String::operator+=(const T& t)
{
    return *this += String(t);
}

String String::operator+(const String& str)
{
    String lhs(*this);
    lhs += str;
    return lhs;
}

char& String::operator[](std::size_t idx)
{
    return m_data.get()[idx];
}

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
            memcpy(
                m_data.get(),
                oldData.get(),
                m_size + 1);
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
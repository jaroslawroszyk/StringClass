#include "String.hpp"

namespace my
{
    String &String::assign(const String &s)
    {
        return *this = s;
    }

    String &String::assign(const char *str)
    {
        return (*this) = String(str);
    }

    String &String::assign(size_t size , char s)
    {
        m_size = size;
        allocateMemory(size);
        std::memset(m_data.get(),s,size);
        m_data[size] = '\0';
        return *this;
    }

    String &String::assign(const char *str , size_t size)
    {
        m_size = size;
        allocateMemory(size);
        std::memcpy(m_data.get(),str,size);
        m_data[size] = '\0';
        return *this;
    }

//    String &String::assign(const String &s , size_t pos , size_t n)
//    {
//        String str(s , pos , n);
//        delete[] m_data;
//        m_size = str.m_size;
//        m_data = new char[m_size];
//        for (std::size_t i = 0; i < m_size; i++)
//            m_data[i] = str.m_data[i];
//        return *this;
//    }
}

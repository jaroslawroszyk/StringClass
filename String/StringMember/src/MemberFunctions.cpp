#include "String.hpp"

namespace my
{
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

    String &String::assign(const String &character)
    {
        return *this = character;
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
////        String str(s , pos , n);
//        m_size = s.size();
////        allocateMemory(s.size());
////        std::memset(m_data.get(),pos,n);
////        std::memset(m_data().get(),pos,s.size());
//        //        delete[] m_data;
////        m_size = str.m_size;
//        for (std::size_t i = 0; i < m_size; i++)
//            m_data[i] = s.m_data[pos + i];
//        m_data[pos] = '\0';
//        return *this;
//    }
}

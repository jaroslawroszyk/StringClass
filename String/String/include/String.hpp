#pragma once

#include <cstdint>
#include <fmt/ostream.h>
#include <iostream>
#include <ostream>
#include <memory>
#include <iterator>

namespace my
{
    class String
    {
    public:
        String();

        explicit String(char);

        explicit String(const char *);

        String(const String &);

        String(String &&);

        String(const String & , const std::size_t, std::size_t);

        String(const char * , std::size_t n);

        String(std::size_t , const char &);

        ~String() = default; //extend to cpp

        // Member Functions
        String &operator=(String &);
        String &operator=(const String &);
        String &operator=(String &&);
        String &assign(const String &);
        String &assign(const char *);
        String &assign(const char * , std::size_t);
        String &assign(size_t , char);
//        String &assign(const String & , std::size_t, std::size_t); todo: add

        // Element Access
        char &at(std::size_t);
        const char &at(std::size_t) const;
        char& operator[](std::size_t idx);
        char& operator[](std::size_t idx) const;
        char& front();
        const char& front() const;
        char& back();
        const char& back() const;
        const char *data() const;
        const char *c_str() const;

        using iterator = char *;
        using const_iterator = const char*;

        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

        //Iterators - todo: own iterator class and reverse iterator class
        iterator begin() noexcept;
        const_iterator begin() const noexcept;
        const_iterator cbegin() const noexcept;
        iterator end() noexcept;
        const_iterator end() const noexcept;
        const_iterator cend() const noexcept;
        reverse_iterator rbegin() noexcept;
        const_reverse_iterator rbegin() const noexcept;
        const_reverse_iterator crbegin() const noexcept;
        reverse_iterator rend() noexcept;
        const_reverse_iterator rend() const noexcept;
        const_reverse_iterator crend() const noexcept;

        // Capacity
        bool empty() const;
        std::size_t length() const noexcept;
        std::size_t size() const noexcept;
        std::size_t capacity() const noexcept;
        void reserve(size_t new_size);
        //shrink_to_fit

        auto Data() const
        { return m_data.get(); }

        // Operators:
        friend std::ostream &operator<<(std::ostream &out , const String &str)
        {
            for (std::size_t i = 0; i < str.m_size; ++i)
                out << str.m_data[i];
            return out << "\n";
        }

        String &operator+=(const String &);

        template<typename T>
        String& operator +=(const T& t);

        String operator+(const String &str);

    private:
        std::unique_ptr<char[]> m_data{nullptr};
        std::size_t m_size = 0;
        std::size_t m_capacity = 0;

        void internal_assign(const char* str, std::size_t n, std::size_t pos = 0);
        void allocateMemory(size_t new_size);
    };
} // namespace my

template<>
struct fmt::formatter<my::String>
{
    constexpr auto parse(format_parse_context &ctx)->decltype(ctx.begin())
    {
        auto it = ctx.begin() , end = ctx.end();
        if (it != end && *it != '}') throw format_error("invalid format");
        return it;
    }

    template<typename FormatContext>
    auto format(const my::String &p , FormatContext &ctx) const->decltype(ctx.out())
    {
        return fmt::format_to(ctx.out() , "{}" , p.Data());
    }
};
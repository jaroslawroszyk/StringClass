#pragma once

#include <fmt/ostream.h>

namespace my
{
class String
{
public:
    using size_type = size_t;

    String();
    explicit String(char);
    explicit String(const char*);
    String(const String&);
    String(String&&);
    String(const String&, const size_type, size_type);
    String(const char*, size_type n);
    String(size_type, const char&);
    ~String() = default;

    // Member Functions
    String& operator=(String&);
    String& operator=(const String&);
    String& operator=(String&&);
    String& assign(const String&);
    String& assign(const char*);
    String& assign(const char*, size_type);
    String& assign(size_type, char);

    // Element Access
    char& at(size_type);
    const char& at(size_type) const;
    char& operator[](size_type);
    char& operator[](size_type) const;
    char& front();
    const char& front() const;
    char& back();
    const char& back() const;
    const char* data() const;
    const char* c_str() const;

    // Iterators - todo: own iterator class and reverse iterator class
    using iterator = char*;
    using const_iterator = const char*;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

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
    size_type length() const noexcept;
    size_type size() const noexcept;
    size_type max_size() const noexcept;
    size_type capacity() const noexcept;
    void reserve(size_type);
    void shrink_to_fit();

    //  Operations
    void clear() noexcept;
    void insert(size_type, const char*);
    void insert(size_type, const String&);
    String& erase(size_type index = 0, size_type count = npos);
    String& push_back(char);
    // pop_back
    // append
    String& operator+=(const String&);
    template <typename T>
    String& operator+=(const T&);
    int compare(const String&) const noexcept;
    // replace
    // substr
    size_type copy(char*, size_type, size_type pos = 0) const;
    // resize
    void swap(String&) noexcept;

    // Constants
    static const size_type npos = -1;

    // Operators:
    String operator+(const String& str);
    auto Data() const { return m_data.get(); }

private:
    std::unique_ptr<char[]> m_data{nullptr};
    size_type m_size = 0;
    size_type m_capacity = 0;
    size_type m_increaseBy = 15;

    // Memory Management
    void internal_assign(const char* str, size_type n, size_type pos = 0);
    void allocateMemory(size_type);
    void increaseCapacity(const size_type);
    void decreaseCapacity(const size_type);
    void setLength(const size_type len);
    size_type getLength(const String&, size_type, size_type) const;

    // Helpers
    inline void _append(const char*);
    void _append(const char* , size_type);
    void _erase(size_type, size_type);
    void clear_str(const size_type );
    void fill_str(char* , const size_type , const size_type , char );
};

// non-member functions
void swap(String&, String&);
bool operator==(const String& lhs, const String& rhs);
std::ostream& operator<<(std::ostream& os, const String& str);
std::istream& operator>>(std::istream& is, String& str);
} // namespace my

template <>
struct fmt::formatter<my::String>
{
    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin())
    {
        auto it = ctx.begin(), end = ctx.end();
        if (it != end && *it != '}') throw format_error("invalid format");
        return it;
    }

    template <typename FormatContext>
    auto format(const my::String& p, FormatContext& ctx) const -> decltype(ctx.out())
    {
        return fmt::format_to(ctx.out(), "{}", p.Data());
    }
};
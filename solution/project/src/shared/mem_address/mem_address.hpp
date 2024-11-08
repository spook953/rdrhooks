#pragma once

#include <compare>

class MemAddr final
{
private:
    uintptr_t m_addr{};

public:
    MemAddr() = default;
    MemAddr(const uintptr_t addr);
    MemAddr(void *const addr);

public:
    MemAddr &operator=(const MemAddr &other);
    MemAddr operator+(const MemAddr &other) const;
    MemAddr operator-(const MemAddr &other) const;
    std::strong_ordering operator<=>(const MemAddr &other) const;
    bool operator==(const MemAddr &other) const;
    explicit operator bool() const;

public:
    uintptr_t get() const;
    void set(const uintptr_t addr);

public:
    MemAddr offset(const size_t offset);
    MemAddr deref(size_t count = 1);
    MemAddr fixRip(const size_t offset = 1);

public:
    template <typename T>
    T rcast() const
    {
        return reinterpret_cast<T>(m_addr);
    }

    template <typename T>
    T scast() const
    {
        return static_cast<T>(m_addr);
    }

    template <typename T, typename... Args>
    inline T call(Args... args) const
    {
        return reinterpret_cast<T(__fastcall *)(Args...)>(m_addr)(args...);
    }
};
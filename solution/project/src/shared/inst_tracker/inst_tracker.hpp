#pragma once

#include <vector>

template <typename T>
class InstTracker;

template<typename T>
const std::vector<T *> &getInsts()
{
    return InstTracker<T>::insts;
}

template <typename T>
class InstTracker
{
private:
    inline static std::vector<T *> insts{};

private:
    friend const std::vector<T *> &getInsts<T>();

public:
    InstTracker(T *const ptr)
    {
        insts.push_back(ptr);
    }
};
#pragma once

#include "base.hpp"

namespace rdr2
{
    template<typename T = float>
    consteval T pi()
    {
        return static_cast<T>(3.14159265358979323846);
    }
}
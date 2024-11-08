/*
    Plugin-SDK (Grand Theft Auto IV) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/

#pragma once

namespace rage
{
    template<typename T = float>
    consteval T pi()
    {
        return static_cast<T>(3.14159265358979323846);
    }
}
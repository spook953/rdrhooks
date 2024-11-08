/*
	Plugin-SDK (Grand Theft Auto IV) header file
	Authors: GTA Community. See more here
	https://github.com/DK22Pac/plugin-sdk
	Do not delete this comment block. Respect others' work!
*/

#pragma once

#include "../../../../shared/shared.hpp"

namespace rage
{
	class Quaternion
	{
	public:
		float x{};
		float y{};
		float z{};
		float w{};

	public:
		Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
	};
}
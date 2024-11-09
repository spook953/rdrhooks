#pragma once

#include "base.hpp"

namespace rdr2
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
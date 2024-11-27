#pragma once

#include "base.hpp"

#include "Vector3.hpp"

namespace rdr2
{
	class phSegment
	{
	public:
		Vector3 start{};
		int unk{};
		Vector3 end{};
	};
}
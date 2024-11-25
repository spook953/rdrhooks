#pragma once

#include "base.hpp"

namespace rdr2
{
	class sagActorComponent
	{
	public:
		bool IsHuman()
		{
			return *reinterpret_cast<int *>(reinterpret_cast<uintptr_t>(this) + 0xA3C) == 0;
		}
	};
}
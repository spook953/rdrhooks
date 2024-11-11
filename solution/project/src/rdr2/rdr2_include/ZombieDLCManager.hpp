#pragma once

#include "base.hpp"

namespace rdr2
{
	class ZombieDLCManager
	{
	public:
		bool IsZombieDLCActive()
		{
			return *reinterpret_cast<bool *>(reinterpret_cast<uintptr_t>(this) + 0xC);
		}
	};
}
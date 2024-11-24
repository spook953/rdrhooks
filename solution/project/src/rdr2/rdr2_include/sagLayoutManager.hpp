#pragma once

#include "base.hpp"

#include "sagLayout.hpp"

namespace rdr2
{
	class sagLayoutManager
	{
	public:
		sagLayout *GetActorLayout()
		{
			return *reinterpret_cast<sagLayout **>(reinterpret_cast<uintptr_t>(this) + 0x10);
		}
	};
}
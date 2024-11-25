#pragma once

#include "base.hpp"

#include "sagGuid.hpp"

namespace rdr2
{
	class sagActor;

	class sagLayout
	{
	public:
		bool DestroyActor(sagGuid param_1, bool param_2)
		{
			return sigs::sagLayout_DestroyActor.call<bool>(this, param_1, param_2);
		}

	public:
		int GetNumActors()
		{
			return *reinterpret_cast<int *>(reinterpret_cast<uintptr_t>(this) + 0x20);
		}

		sagActor **First()
		{
			return *reinterpret_cast<rdr2::sagActor ***>(reinterpret_cast<uintptr_t>(this) + 0x10);
		}

		sagActor **Next(sagActor **const it)
		{
			if (!it) {
				return nullptr;
			}

			return *reinterpret_cast<rdr2::sagActor ***>(reinterpret_cast<uintptr_t>(it) + 0x8);
		}
	};
}
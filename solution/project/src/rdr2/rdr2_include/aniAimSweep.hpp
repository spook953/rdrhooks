#pragma once

#include "base.hpp"

namespace rdr2
{
	class aniAimSweep
	{
	public:
		void Reset()
		{
			sigs::aniAimSweep_Reset.call<void>(this);
		}
	};
}
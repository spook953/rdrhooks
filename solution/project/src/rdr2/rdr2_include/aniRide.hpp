#pragma once

#include "base.hpp"

namespace rdr2
{
	class aniRide
	{
	public:
		void FastDismount(bool param_1, bool param_2)
		{
			sigs::aniRide_FastDismount.call<void>(this, param_1, param_2);
		}
	};
}
#pragma once

#include "base.hpp"

namespace rdr2
{
	class aniNavigationGait
	{
	public:
		void Set(aniNavigationGait *param_1)
		{
			sigs::aniNavigationGait_Set.call<void>(this, param_1);
		}
	};
}
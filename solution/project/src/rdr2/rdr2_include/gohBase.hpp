#pragma once

#include "base.hpp"

namespace rdr2
{
	class gohBase
	{
	public:
		void Destroy(bool param_1)
		{
			sigs::gohBase_Destroy.call<void>(this, param_1);
		}
	};
}
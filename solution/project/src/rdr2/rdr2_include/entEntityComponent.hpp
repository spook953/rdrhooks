#pragma once

#include "base.hpp"

#include "sagMsgDestroyOnDeathNotify.hpp"

namespace rdr2
{
	class entEntityComponent
	{
	public:
		void HandleDestroyOnDeathNotify_newbodies(sagMsgDestroyOnDeathNotify *param_1)
		{
			sigs::entEntityComponent_HandleDestroyOnDeathNotify_newbodies.call<void>(this, param_1);
		}
	};
}
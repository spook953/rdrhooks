#pragma once

#include "base.hpp"

namespace rdr2
{
	class animAnimSetHandle
	{
	public:
		void *GetObject()
		{
			return sigs::animAnimSetHandle_GetObject.call<void *>(this);
		}
	};
}
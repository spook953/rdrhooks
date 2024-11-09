#pragma once

#include "base.hpp"

namespace rdr2
{
	class aniLedge
	{
	public:
		void CancelLedge()
		{
			sigs::aniLedge_CancelLedge.call<void>(this);
		}
	};
}
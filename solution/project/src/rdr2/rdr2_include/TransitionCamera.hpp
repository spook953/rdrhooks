#pragma once

#include "base.hpp"

namespace rdr2
{
	class TransitionCamera
	{
	public:
		void Reset()
		{
			sigs::TransitionCamera_Reset.call<void>(this);
		}
	};
}
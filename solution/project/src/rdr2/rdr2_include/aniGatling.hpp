#pragma once

#include "base.hpp"

namespace rdr2
{
	class aniGatling
	{
	public:
		void UpdateWeaponLocation()
		{
			sigs::aniGatling_UpdateWeaponLocation.call<void>(this);
		}
	};
}
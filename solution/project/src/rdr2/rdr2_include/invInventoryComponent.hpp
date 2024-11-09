#pragma once

#include "base.hpp"

namespace rdr2
{
	class invInventoryComponent
	{
	public:
		bool IsItemSwitchingWeaponToWeapon()
		{
			return sigs::invInventoryComponent_IsItemSwitchingWeaponToWeapon.call<bool>(this);
		}
	};
}
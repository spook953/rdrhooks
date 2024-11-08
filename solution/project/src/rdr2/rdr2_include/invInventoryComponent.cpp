#include "invInventoryComponent.hpp"

bool rdr2::invInventoryComponent::IsItemSwitchingWeaponToWeapon()
{
	return sigs::invInventoryComponent_IsItemSwitchingWeaponToWeapon.call<bool>(this);
}
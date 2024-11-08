#include "weapWeapon.hpp"

float &rdr2::weapWeapon::GetAmmoInClip()
{
	return *reinterpret_cast<float *>(reinterpret_cast<uintptr_t>(this) + 0x12C);
}

int &rdr2::weapWeapon::GetAutoFire()
{
	return *reinterpret_cast<int *>(*reinterpret_cast<uintptr_t *>(reinterpret_cast<uintptr_t>(this) + 0x28) + 0x1B0);
}
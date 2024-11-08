#include "weapWeapon.hpp"

float &rdr2::weapWeapon::GetAmmoInClip()
{
	return *reinterpret_cast<float *>(reinterpret_cast<uintptr_t>(this) + 0x12C);
}

int &rdr2::weapWeapon::GetAutoFire()
{
	return *reinterpret_cast<int *>(*reinterpret_cast<uintptr_t *>(reinterpret_cast<uintptr_t>(this) + 0x28) + 0x1B0);
}

void rdr2::weapWeapon::ClampVelocityToMaxFlatDist(rage::Vector3 *param_1)
{
	sigs::weapWeapon_ClampVelocityToMaxFlatDist.call<void>(this, param_1);
}

void rdr2::weapWeapon::ComputeMainMuzzlePosition(rage::Vector3 *param_1, float param_2, bool param_3)
{
	sigs::weapWeapon_ComputeMainMuzzlePosition.call<void>(this, param_1, param_2, param_3);
}

void rdr2::weapWeapon::GetMuzzleLocationMatrix(rage::Matrix34 *param_1, bool param_2)
{
	sigs::weapWeapon_GetMuzzleLocationMatrix.call<void>(this, param_1, param_2);
}

bool rdr2::weapWeapon::UpdateOpMode()
{
	return sigs::weapWeapon_UpdateOpMode.call<bool>(this);
}

float rdr2::weapWeapon::GetThrownArmingDistanceSqrd(rage::Vector3 *param_1)
{
	return sigs::weapWeapon_GetThrownArmingDistanceSqrd.call<float>(this, param_1);
}

bool rdr2::weapWeapon::IsThrownExploding()
{
	return sigs::weapWeapon_IsThrownExploding.call<bool>(this);
}

void rdr2::weapWeapon::AddAmmo(AmmoComponent *param_1, float param_2)
{
	sigs::weapWeapon_AddAmmo.call<void>(this, param_1, param_2);
}

void rdr2::weapWeapon::UpdateRemoteGatlingData()
{
	sigs::weapWeapon_UpdateRemoteGatlingData.call<void>(this);
}

void rdr2::weapWeapon::SetAmmo(AmmoComponent *param_1, float param_2)
{
	sigs::weapWeapon_SetAmmo.call<void>(this, param_1, param_2);
}

void rdr2::weapWeapon::UpdateSkeletonState()
{
	sigs::weapWeapon_UpdateSkeletonState.call<void>(this);
}

void rdr2::weapWeapon::Shutdown(AmmoComponent *param_1)
{
	sigs::weapWeapon_Shutdown.call<void>(this, param_1);
}

void rdr2::weapWeapon::UpdateAudio(bool param_1)
{
	sigs::weapWeapon_UpdateAudio.call<void>(this, param_1);
}

void rdr2::weapWeapon::FireProjectile(projProjectile *param_1, int param_2, rage::Matrix34 *param_3, float param_4, int param_5, bool param_6, int param_7, bool param_8)
{
	sigs::weapWeapon_FireProjectile.call<void>(this, param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
}

void rdr2::weapWeapon::CreateExplodingProjectile()
{
	sigs::weapWeapon_CreateExplodingProjectile.call<void>(this);
}

void rdr2::weapWeapon::FindAndFireOpMode(ProjectileLaunchData *param_1)
{
	sigs::weapWeapon_FindAndFireOpMode.call<void>(this, param_1);
}

void rdr2::weapWeapon::SetDrawn(bool param_1)
{
	sigs::weapWeapon_SetDrawn.call<void>(this, param_1);
}

void rdr2::weapWeapon::Init(AmmoComponent *param_1, weapBaseWeaponType *param_2, sagGuid param_3, bool param_4)
{
	sigs::weapWeapon_Init.call<void>(this, param_1, param_2, param_3, param_4);
}

void rdr2::weapWeapon::FireProjectileRemote(ProjectileLaunchData *param_1)
{
	sigs::weapWeapon_FireProjectileRemote.call<void>(this, param_1);
}

void rdr2::weapWeapon::OnFireProjectile(weapProjectileInfo *param_1)
{
	sigs::weapWeapon_OnFireProjectile.call<void>(this, param_1);
}
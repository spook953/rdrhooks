#pragma once

#include "base.hpp"

#include "AmmoComponent.hpp"
#include "Matrix34.hpp"
#include "ProjectileLaunchData.hpp"
#include "projProjectile.hpp"
#include "sagGuid.hpp"
#include "Vector3.hpp"
#include "weapBaseWeaponType.hpp"
#include "weapProjectileInfo.hpp"

namespace rdr2
{
	class weapWeapon
	{
	public:
		void ClampVelocityToMaxFlatDist(Vector3 *param_1)
		{
			sigs::weapWeapon_ClampVelocityToMaxFlatDist.call<void>(this, param_1);
		}

		void ComputeMainMuzzlePosition(Vector3 *param_1, float param_2, bool param_3)
		{
			sigs::weapWeapon_ComputeMainMuzzlePosition.call<void>(this, param_1, param_2, param_3);
		}

		void GetMuzzleLocationMatrix(Matrix34 *param_1, bool param_2)
		{
			sigs::weapWeapon_GetMuzzleLocationMatrix.call<void>(this, param_1, param_2);
		}

		bool UpdateOpMode()
		{
			return sigs::weapWeapon_UpdateOpMode.call<bool>(this);
		}

		float GetThrownArmingDistanceSqrd(Vector3 *param_1)
		{
			return sigs::weapWeapon_GetThrownArmingDistanceSqrd.call<float>(this, param_1);
		}

		bool IsThrownExploding()
		{
			return sigs::weapWeapon_IsThrownExploding.call<bool>(this);
		}

		void AddAmmo(AmmoComponent *param_1, float param_2)
		{
			sigs::weapWeapon_AddAmmo.call<void>(this, param_1, param_2);
		}

		void UpdateRemoteGatlingData()
		{
			sigs::weapWeapon_UpdateRemoteGatlingData.call<void>(this);
		}

		void SetAmmo(AmmoComponent *param_1, float param_2)
		{
			sigs::weapWeapon_SetAmmo.call<void>(this, param_1, param_2);
		}

		void UpdateSkeletonState()
		{
			sigs::weapWeapon_UpdateSkeletonState.call<void>(this);
		}

		void Shutdown(AmmoComponent *param_1)
		{
			sigs::weapWeapon_Shutdown.call<void>(this, param_1);
		}

		void UpdateAudio(bool param_1)
		{
			sigs::weapWeapon_UpdateAudio.call<void>(this, param_1);
		}

		void FireProjectile(projProjectile *param_1, int param_2, Matrix34 *param_3, float param_4, int param_5, bool param_6, int param_7, bool param_8)
		{
			sigs::weapWeapon_FireProjectile.call<void>(this, param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
		}

		void CreateExplodingProjectile()
		{
			sigs::weapWeapon_CreateExplodingProjectile.call<void>(this);
		}

		void FindAndFireOpMode(ProjectileLaunchData *param_1)
		{
			sigs::weapWeapon_FindAndFireOpMode.call<void>(this, param_1);
		}

		void SetDrawn(bool param_1)
		{
			sigs::weapWeapon_SetDrawn.call<void>(this, param_1);
		}

		void Init(AmmoComponent *param_1, weapBaseWeaponType *param_2, sagGuid param_3, bool param_4)
		{
			sigs::weapWeapon_Init.call<void>(this, param_1, param_2, param_3, param_4);
		}

		void FireProjectileRemote(ProjectileLaunchData *param_1)
		{
			sigs::weapWeapon_FireProjectileRemote.call<void>(this, param_1);
		}

		void OnFireProjectile(weapProjectileInfo *param_1)
		{
			sigs::weapWeapon_OnFireProjectile.call<void>(this, param_1);
		}

		void Update(Matrix34 *param_1, Vector3 *param_2, bool param_3, float param_4)
		{
			sigs::weapWeapon_Update.call<void>(this, param_1, param_2, param_3, param_4);
		}

	public:
		float &GetAmmoInClip()
		{
			return *reinterpret_cast<float *>(reinterpret_cast<uintptr_t>(this) + 0x12C);
		}

		int &GetAutoFire()
		{
			return *reinterpret_cast<int *>(*reinterpret_cast<uintptr_t *>(reinterpret_cast<uintptr_t>(this) + 0x28) + 0x1B0);
		}
	};
}
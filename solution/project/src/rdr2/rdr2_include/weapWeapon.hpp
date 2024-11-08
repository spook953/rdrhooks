#pragma once

#include "base.hpp"

#include "AmmoComponent.hpp"
#include "ProjectileLaunchData.hpp"
#include "projProjectile.hpp"
#include "sagGuid.hpp"
#include "weapBaseWeaponType.hpp"
#include "weapProjectileInfo.hpp"

namespace rdr2
{
	class weapWeapon
	{
	public:
		float &GetAmmoInClip();
		int &GetAutoFire();
		void ClampVelocityToMaxFlatDist(rage::Vector3 *param_1);
		void ComputeMainMuzzlePosition(rage::Vector3 *param_1, float param_2, bool param_3);
		void GetMuzzleLocationMatrix(rage::Matrix34 *param_1, bool param_2);
		bool UpdateOpMode();
		float GetThrownArmingDistanceSqrd(rage::Vector3 *param_1);
		bool IsThrownExploding();
		void AddAmmo(AmmoComponent *param_1, float param_2);
		void UpdateRemoteGatlingData();
		void SetAmmo(AmmoComponent *param_1, float param_2);
		void UpdateSkeletonState();
		void Shutdown(AmmoComponent *param_1);
		void UpdateAudio(bool param_1);
		void FireProjectile(projProjectile *param_1, int param_2, rage::Matrix34 *param_3, float param_4, int param_5, bool param_6, int param_7, bool param_8);
		void CreateExplodingProjectile();
		void FindAndFireOpMode(ProjectileLaunchData *param_1);
		void SetDrawn(bool param_1);
		void Init(AmmoComponent *param_1, weapBaseWeaponType *param_2, sagGuid param_3, bool param_4);
		void FireProjectileRemote(ProjectileLaunchData *param_1);
		void OnFireProjectile(weapProjectileInfo *param_1);
	};
}
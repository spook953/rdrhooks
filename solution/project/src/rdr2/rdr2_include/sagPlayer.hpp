#pragma once

#include "base.hpp"

#include "animAnimatorComponent.hpp"
#include "eCodeSideStatistics.hpp"
#include "eState.hpp"
#include "invInventoryComponent.hpp"
#include "invWeaponType.hpp"
#include "mvrMoverComponent.hpp"
#include "tgtReticleComponent.hpp"
#include "WeaponSpecialRequest.hpp"
#include "weapWeapon.hpp"

namespace rdr2
{
	class sagPlayer
	{
	public:
		bool CanSniperZoom(bool param_1);
		weapWeapon *GetActiveWeapon(bool param_1);
		bool CanQuickPickActivate();
		void UpdateJumpHotspot();
		void ChangeState(eState param_1);
		void SetDeadEyeDueling(bool param_1, bool param_2);
		void HandleFallThrough(mvrMoverComponent *param_1);
		void UpdateWpnRadialSelectInput();
		void UpdateReticle(animAnimatorComponent *param_1);
		void Update(eState param_1);
		void StorePlayerData();
		void PostCameraUpdate();
		void UpdateHudReticles(animAnimatorComponent *param_1, tgtReticleComponent *param_2, invInventoryComponent *param_3);
		bool CanDrawWeaponOfType(invWeaponType *param_1);
		void UpdateTargeting(invInventoryComponent *param_1);
		void UpdateStateVehicle();
		void EndDeadEyeCommon();
		void CancelDeadeye();
		void UpdateAttackInput(invInventoryComponent *param_1);
		void UpdateWeaponSpecialMove(WeaponSpecialRequest param_1);
		void ResetData();
		void UpdateStateHorse();
		void UpdateInput();
		void UpdateZoomState();
		void UpdateFoot();
		void IncrementStat(eCodeSideStatistics param_1, eCodeSideStatistics param_2);
		void UpdateState(eState param_1);
		void UpdateWeaponSelection(int param_1);
	};
}
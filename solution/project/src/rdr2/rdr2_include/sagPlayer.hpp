#pragma once

#include "base.hpp"

#include "animAnimatorComponent.hpp"
#include "eCodeSideStatistics.hpp"
#include "eState.hpp"
#include "invInventoryComponent.hpp"
#include "invWeaponType.hpp"
#include "mvrMoverComponent.hpp"
#include "sagPlayerStates.hpp"
#include "tgtReticleComponent.hpp"
#include "WeaponSpecialRequest.hpp"
#include "weapWeapon.hpp"

namespace rdr2
{
	class sagPlayer
	{
	public:
		bool CanSniperZoom(bool param_1)
		{
			return sigs::sagPlayer_CanSniperZoom.call<bool>(this, param_1);
		}

		weapWeapon *GetActiveWeapon(bool param_1)
		{
			return sigs::sagPlayer_GetActiveWeapon.call<weapWeapon *>(this, param_1);
		}

		bool CanQuickPickActivate()
		{
			return sigs::sagPlayer_CanQuickPickActivate.call<bool>(this);
		}

		void UpdateJumpHotspot()
		{
			sigs::sagPlayer_UpdateJumpHotspot.call<void>(this);
		}

		void ChangeState(eState param_1)
		{
			sigs::sagPlayer_ChangeState.call<void>(this, param_1);
		}

		void SetDeadEyeDueling(bool param_1, bool param_2)
		{
			sigs::sagPlayer_SetDeadEyeDueling.call<void>(this, param_1, param_2);
		}

		void HandleFallThrough(mvrMoverComponent *param_1)
		{
			sigs::sagPlayer_HandleFallThrough.call<void>(this, param_1);
		}

		void UpdateWpnRadialSelectInput()
		{
			sigs::sagPlayer_UpdateWpnRadialSelectInput.call<void>(this);
		}

		void UpdateReticle(animAnimatorComponent *param_1)
		{
			sigs::sagPlayer_UpdateReticle.call<void>(this, param_1);
		}

		void Update(eState param_1)
		{
			sigs::sagPlayer_Update.call<void>(this, param_1);
		}

		void StorePlayerData()
		{
			sigs::sagPlayer_StorePlayerData.call<void>(this);
		}

		void PostCameraUpdate()
		{
			sigs::sagPlayer_PostCameraUpdate.call<void>(this);
		}

		void UpdateHudReticles(animAnimatorComponent *param_1, tgtReticleComponent *param_2, invInventoryComponent *param_3)
		{
			sigs::sagPlayer_UpdateHudReticles.call<void>(this, param_1, param_2, param_3);
		}

		bool CanDrawWeaponOfType(invWeaponType *param_1)
		{
			return sigs::sagPlayer_CanDrawWeaponOfType.call<bool>(this, param_1);
		}

		void UpdateTargeting(invInventoryComponent *param_1)
		{
			sigs::sagPlayer_UpdateTargeting.call<void>(this, param_1);
		}

		void UpdateStateVehicle()
		{
			sigs::sagPlayer_UpdateStateVehicle.call<void>(this);
		}

		void EndDeadEyeCommon()
		{
			sigs::sagPlayer_EndDeadEyeCommon.call<void>(this);
		}

		void CancelDeadeye()
		{
			sigs::sagPlayer_CancelDeadeye.call<void>(this);
		}

		void UpdateAttackInput(invInventoryComponent *param_1)
		{
			sigs::sagPlayer_UpdateAttackInput.call<void>(this, param_1);
		}

		void UpdateWeaponSpecialMove(WeaponSpecialRequest param_1)
		{
			sigs::sagPlayer_UpdateWeaponSpecialMove.call<void>(this, param_1);
		}

		void ResetData()
		{
			sigs::sagPlayer_ResetData.call<void>(this);
		}

		void UpdateStateHorse()
		{
			sigs::sagPlayer_UpdateStateHorse.call<void>(this);
		}

		void UpdateInput()
		{
			sigs::sagPlayer_UpdateInput.call<void>(this);
		}

		void UpdateZoomState()
		{
			sigs::sagPlayer_UpdateZoomState.call<void>(this);
		}

		void UpdateFoot()
		{
			sigs::sagPlayer_UpdateFoot.call<void>(this);
		}

		void IncrementStat(eCodeSideStatistics param_1, eCodeSideStatistics param_2)
		{
			sigs::sagPlayer_IncrementStat.call<void>(this, param_1, param_2);
		}

		void UpdateState(eState param_1)
		{
			sigs::sagPlayer_UpdateState.call<void>(this, param_1);
		}

		void UpdateWeaponSelection(int param_1)
		{
			sigs::sagPlayer_UpdateWeaponSelection.call<void>(this, param_1);
		}

		void Reset()
		{
			sigs::sagPlayer_Reset.call<void>(this);
		}

	public:
		sagPlayerStates *GetPlayerStates()
		{
			return *reinterpret_cast<sagPlayerStates **>(reinterpret_cast<uintptr_t>(this) + 0x410);
		}
	};
}
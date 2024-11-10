#pragma once

#include "base.hpp"

#include "gohGUID.hpp"
#include "rdrAnimation.hpp"
#include "Vector3.hpp"

namespace rdr2
{
	class aniAim
	{
	public:
		void UpdateWeaponAttachment()
		{
			sigs::aniAim_UpdateWeaponAttachment.call<void>(this);
		}

		void Update(float param_1)
		{
			sigs::aniAim_Update.call<void>(this, param_1);
		}

		void SetAim(bool param_1, gohGUID param_2, Vector3 *param_3, int param_4, Vector3 *param_5)
		{
			sigs::aniAim_SetAim.call<void>(this, param_1, param_2, param_3, param_4, param_5);
		}

		void FastDraw()
		{
			sigs::aniAim_FastDraw.call<void>(this);
		}

		bool RequestReload()
		{
			return sigs::aniAim_RequestReload.call<bool>(this);
		}

		void Throw()
		{
			sigs::aniAim_Throw.call<void>(this);
		}

		bool ScheduleThrow(rdrAnimation *param_1, float param_2, float param_3, float param_4, float param_5, float param_6, int param_7)
		{
			return sigs::aniAim_ScheduleThrow.call<bool>(this, param_1, param_2, param_3, param_4, param_5, param_6, param_7);
		}

		bool Fire()
		{
			return sigs::aniAim_Fire.call<bool>(this);
		}

		void AddReloadToFrameMT()
		{
			sigs::aniAim_AddReloadToFrameMT.call<void>(this);
		}

		void FillAimFrameMT()
		{
			sigs::aniAim_FillAimFrameMT.call<void>(this);
		}

		void AddDrawHolsterToFrameMT()
		{
			sigs::aniAim_AddDrawHolsterToFrameMT.call<void>(this);
		}

		void UpdateInternalStates(bool param_1)
		{
			sigs::aniAim_UpdateInternalStates.call<void>(this, param_1);
		}
	};
}
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

		void RequestFire()
		{
			sigs::aniGatling_RequestFire.call<void>(this);
		}

		void Reset()
		{
			sigs::aniGatling_Reset.call<void>(this);
		}

		void Update()
		{
			sigs::aniGatling_Update.call<void>(this);
		}

		void UpdateGatlingMachine()
		{
			sigs::aniGatling_UpdateGatlingMachine.call<void>(this);
		}

		void UpdateBoneIDs()
		{
			sigs::aniGatling_UpdateBoneIDs.call<void>(this);
		}

		void UpdateIK()
		{
			sigs::aniGatling_UpdateIK.call<void>(this);
		}
	};
}
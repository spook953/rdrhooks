#pragma once

#include "base.hpp"

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
	};
}
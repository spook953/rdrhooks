#pragma once

#include "base.hpp"

#include "gohGUID.hpp"

namespace rdr2
{
	class aniAnimProp
	{
	public:
		void UpdatePropAttachments()
		{
			sigs::aniAnimProp_UpdatePropAttachments.call<void>(this);
		}

		bool SetProp(char *param_1, gohGUID param_2, Matrix34 *param_3, bool param_4, int param_5)
		{
			return sigs::aniAnimProp_SetProp.call<bool>(this, param_1, param_2, param_3, param_4, param_5);
		}

		void Shutdown()
		{
			sigs::aniAnimProp_Shutdown.call<void>(this);
		}
	};
}
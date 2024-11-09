#pragma once

#include "base.hpp"

namespace rdr2
{
	class aniAnimProp
	{
	public:
		void UpdatePropAttachments()
		{
			sigs::aniAnimProp_UpdatePropAttachments.call<void>(this);
		}
	};
}
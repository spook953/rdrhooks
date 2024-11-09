#pragma once

#include "base.hpp"

#include "eObjectState.hpp"
#include "phInst.hpp"

namespace rdr2
{
	class phLevelNew
	{
	public:
		//void?
		void AddObject(phInst *param_1, eObjectState param_2, void *param_3, bool param_4)
		{
			sigs::phLevelNew_AddObject.call<void>(this, param_1, param_2, param_3, param_4);
		}

		//void?
		void AddObjectHelper(phInst *param_1, eObjectState param_2, void *param_3)
		{
			sigs::phLevelNew_AddObjectHelper.call<void>(this, param_1, param_2, param_3);
		}
	};
}
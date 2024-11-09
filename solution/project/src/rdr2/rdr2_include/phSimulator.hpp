#pragma once

#include "base.hpp"

#include "phInst.hpp"
#include "Matrix34.hpp"

namespace rdr2
{
	class phSimulator
	{
	public:
		bool MoveObject(phInst *param_1, Matrix34 *param_2, Matrix34 *param_3)
		{
			return sigs::phSimulator_MoveObject.call<bool>(this, param_1, param_2, param_3);
		}

		//void?
		void AddFixedObject(phInst *param_1)
		{
			sigs::phSimulator_AddFixedObject.call<void>(this, param_1);
		}
	};
}
#pragma once

#include "base.hpp"

#include "Gamepad_c.hpp"

namespace rdr2
{
	class InputSystem_c
	{
	public:
		Gamepad_c *GetGamepad(int param_1)
		{
			return sigs::InputSystem_c_GetGamepad.call<Gamepad_c *>(this, param_1);
		}
	};
}
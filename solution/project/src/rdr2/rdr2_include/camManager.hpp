#pragma once

#include "gohCameraFactory.hpp"

namespace rdr2
{
	class camManager
	{
	public:
		gohCameraFactory *const GetCameraFactory();
	};
}
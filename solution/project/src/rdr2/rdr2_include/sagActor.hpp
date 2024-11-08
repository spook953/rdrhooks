#pragma once

#include "rage/rage.hpp"

namespace rdr2
{
	class sagActor
	{
	public:
		void *GetInstance();
		bool IsIndoors();
		bool GetHeadPosition(rage::Vector3 &param_1);
		bool GetRootPosition(rage::Vector3 &param_1);
	};
}
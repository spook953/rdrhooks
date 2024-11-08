#pragma once

#include "rage/rage.hpp"

namespace rdr2
{
	enum eCameraType : int
	{
		CAM_0,
		CAM_1
	};

	class gohCamera
	{
	private:
		uint8_t field_0[16]{};

	public:
		rage::Matrix44 m_mMatrix{};
	};
}
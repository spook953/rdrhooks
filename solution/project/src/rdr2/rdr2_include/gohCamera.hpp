#pragma once

#include "base.hpp"

#include "Matrix44.hpp"

namespace rdr2
{
	enum eCameraType : int
	{
		CAM_0,
		CAM_1,
		CAM_2,
		CAM_3
	};

	class gohCamera
	{
	private:
		uint8_t field_0[16]{};

	public:
		Matrix44 m_mMatrix{};
	};
}
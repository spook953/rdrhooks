#pragma once

#include "base.hpp"

#include "grcViewport.hpp"
#include "Matrix44.hpp"

namespace rdr2
{
	class CameraViewport
	{
	private:
		char pad_000[16]{};

	public:
		Matrix44 m_Matrix1{};

	private:
		char pad_003[232 - 16]{};

	public:
		float m_Fov{};

	public:
		void SetCameraMatrix(const Matrix44 &matrix)
		{
			sigs::CameraViewport_SetCameraMatrix.call<void, void *, const Matrix44 &>(this, matrix);
		}

		void Update()
		{
			sigs::CameraViewport_Update.call<void>(this);
		}

		void Lerp(float param_1, CameraViewport *param_2, CameraViewport *param_3)
		{
			sigs::CameraViewport_Lerp.call<void>(this, param_1, param_2, param_3);
		}

		void LerpArc(float param_1, CameraViewport *param_2, Vector3 *param_3, float param_4, CameraViewport *param_5, Vector3 *param_6, float param_7, Vector3 *param_8)
		{
			sigs::CameraViewport_LerpArc.call<void>(this, param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
		}

		void Reset()
		{
			sigs::CameraViewport_Reset.call<void>(this);
		}
	};
}
#include "CameraViewport.hpp"

void rdr2::CameraViewport::SetCameraMatrix(rage::Matrix34 *param_1)
{
	sigs::CameraViewport_SetCameraMatrix.call<void>(this, param_1);
}

rdr2::grcViewport *rdr2::CameraViewport::GetViewport()
{
	return *reinterpret_cast<grcViewport **>(reinterpret_cast<uintptr_t>(this) + 0x150);
}
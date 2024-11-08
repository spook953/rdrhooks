#include "CameraViewport.hpp"

void rdr2::CameraViewport::SetCameraMatrix(rage::Matrix34 *param_1)
{
	static const MemAddr addr{ mem::findBytes("RDR.exe", "48 83 EC 28 44 8B 89 ? ? ? ?") };

	if (!addr) {
		return;
	}

	addr.call<void>(this, param_1);
}

rdr2::grcViewport *rdr2::CameraViewport::GetViewport()
{
	return *reinterpret_cast<grcViewport **>(reinterpret_cast<uintptr_t>(this) + 0x150);
}
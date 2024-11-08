#include "camCameraChannel.hpp"

void rdr2::camCameraChannel::RemoveCamera(camCamera *param_1)
{
	static const MemAddr addr{ mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8B 53 38 45 33 C9").fixRip() };

	if (!addr) {
		return;
	}

	addr.call<void>(this, param_1);
}

void rdr2::camCameraChannel::PushCamera(camCamera *param_1, camCameraTransitionBase *param_2, camCameraTransitionBase *param_3)
{
	static const MemAddr addr{ mem::findBytes("RDR.exe", "E9 ? ? ? ? 41 83 F8 FF").fixRip() };

	if (!addr) {
		return;
	}

	addr.call<void>(this, param_1, param_2, param_3);
}
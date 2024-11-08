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

void rdr2::camCameraChannel::Update()
{
	static const MemAddr addr{ mem::findBytes("RDR.exe", "48 89 5C 24 ? 57 48 83 EC 20 48 8B 59 18 48 8B F9 48 89 5C 24 ?") };

	if (!addr) {
		return;
	}

	addr.call<void>(this);
}

rdr2::CameraViewport *rdr2::camCameraChannel::GetCameraViewport()
{
	return *reinterpret_cast<CameraViewport **>(reinterpret_cast<uintptr_t>(this) + 0x40);
}

rdr2::gohDofSettings *rdr2::camCameraChannel::GetDofSettings()
{
	return *reinterpret_cast<gohDofSettings **>(reinterpret_cast<uintptr_t>(this) + 0x610);
}

rdr2::TransitionCamera *rdr2::camCameraChannel::GetTransitionCamera()
{
	return *reinterpret_cast<TransitionCamera **>(reinterpret_cast<uintptr_t>(this) + 0x18);
}
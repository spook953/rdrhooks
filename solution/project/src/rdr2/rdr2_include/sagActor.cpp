#include "sagActor.hpp"

void *rdr2::sagActor::GetInstance()
{
	static const MemAddr addr{ mem::findBytes("RDR.exe", "E8 ? ? ? ? 4C 8B 76 30").fixRip() };

	if (!addr) {
		return nullptr;
	}

	return addr.call<void *, sagActor *>(this);
}

bool rdr2::sagActor::IsIndoors()
{
	static const MemAddr addr{ mem::findBytes("RDR.exe", "E8 ? ? ? ? 44 88 65 63").fixRip() };

	if (!addr) {
		return false;
	}

	return addr.call<bool, sagActor *>(this);
}

bool rdr2::sagActor::GetHeadPosition(rage::Vector3 &param_1)
{
	static const MemAddr addr{ mem::findBytes("RDR.exe", "E8 ? ? ? ? 48 8D 55 80 48 8B CB").fixRip() };

	if (!addr) {
		return false;
	}

	return addr.call<bool, sagActor *, rage::Vector3 &>(this, param_1);
}

bool rdr2::sagActor::GetRootPosition(rage::Vector3 &param_1)
{
	static const MemAddr addr{ mem::findBytes("RDR.exe", "E8 ? ? ? ? C6 47 19 01").fixRip() };

	if (!addr) {
		return false;
	}

	return addr.call<bool, sagActor *, rage::Vector3 &>(this, param_1);
}
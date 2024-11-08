#include "shared/shared.hpp"

bool rdrhLoad()
{
	if (MH_Initialize() != MH_OK) {
		con::printErr("failed to initialize minhook");
		return false;
	}

	con::printMsg("minhook initialized");

	for (Hook *const h : getInsts<Hook>())
	{
		if (!h->init()) {
			con::printErr(std::format("failed to hook: {}", h->name()));
			return false;
		}

		con::printMsg(std::format("hooked {}", h->name()));
	}

	if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
		con::printErr("failed to enable all hooks");
		return false;
	}

	con::printMsg("all hooks enabled");

	return true;
}

bool rdrhUnload()
{
	if (MH_Uninitialize() != MH_OK) {
		con::printErr("minhook failed to uninitialize");
		return false;
	}

	return true;
}

DWORD WINAPI mainThread(LPVOID param)
{
	con::alloc("rdrh");

	if (rdrhLoad())
	{
		con::printMsg("loaded");

		while (!GetAsyncKeyState(VK_F11)) {
			Sleep(100);
		}
	}

	rdrhUnload();

	con::printMsg("unloaded");

	con::free();

	FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(param), EXIT_SUCCESS);
}

BOOL WINAPI DllMain(HINSTANCE inst, DWORD reason, LPVOID reserved)
{
	if (reason != DLL_PROCESS_ATTACH) {
		return FALSE;
	}

	const HANDLE main_thread{ CreateThread(0, 0, mainThread, inst, 0, 0) };

	if (!main_thread) {
		return FALSE;
	}

	CloseHandle(main_thread);

	return TRUE;
}
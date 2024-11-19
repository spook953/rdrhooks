#include "utils/utils.hpp"

bool rdrhLoad()
{
	for (Sig *const s : getInsts<Sig>())
	{
		if (!s->init()) {
			con::printErr(std::format("failed to find {}\n", s->name()));
			return false;
		}

		con::printMsg(std::format("found {} at {:X}\n", s->name(), s->addr().get()));
	}

	if (MH_Initialize() != MH_OK) {
		con::printErr("failed to initialize minhook\n");
		return false;
	}

	for (Hook *const h : getInsts<Hook>())
	{
		if (!h->init()) {
			con::printErr(std::format("failed to hook {}\n", h->name()));
			return false;
		}

		con::printMsg(std::format("hooked {}\n", h->name()));
	}

	if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
		con::printErr("failed to enable all hooks\n");
		return false;
	}

	return true;
}

bool rdrhUnload()
{
	if (MH_Uninitialize() != MH_OK) {
		con::printErr("minhook failed to uninitialize\n");
		return false;
	}

	return true;
}

DWORD WINAPI mainThread(LPVOID param)
{
	con::alloc("rdrh");

	if (rdrhLoad())
	{
		con::printOke("loaded\n");

		while (!GetAsyncKeyState(VK_F11)) {
			Sleep(100);
		}
	}

	rdrhUnload();

	con::printOke("unloaded\n");

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
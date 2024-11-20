#include "core/core.hpp"

DWORD DllMainThread(LPVOID param)
{
	Core::entry();

	FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(param), EXIT_SUCCESS);
}

BOOL DllMain(HINSTANCE inst, DWORD reason, LPVOID reserved)
{
	DisableThreadLibraryCalls(inst);

	if (reason != DLL_PROCESS_ATTACH) {
		return FALSE;
	}

	const HANDLE main_thread{ CreateThread(0, 0, DllMainThread, inst, 0, 0) };

	if (!main_thread) {
		return FALSE;
	}

	CloseHandle(main_thread);

	return TRUE;
}
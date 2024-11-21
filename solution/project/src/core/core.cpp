#include "core.hpp"

bool Core::load()
{
	if (MH_Initialize() != MH_OK) {
		con::printErr("failed to initialize minhook\n");
		return false;
	}

	for (Sig *const s : getInsts<Sig>())
	{
		if (!s->init()) {
			con::printErr(std::format("failed to find {}\n", s->name()));
			return false;
		}

		con::printMsg(std::format("found {} at {:X}\n", s->name(), s->addr().get()));
	}

	if (!Renderer::init()) {
		con::printErr("failed to initialize renderer\n");
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

	return true;
}

bool Core::unload()
{
	for (Hook *const h : getInsts<Hook>())
	{
		if (!h->remove()) {
			con::printErr(std::format("failed to unhook {}\n", h->name()));
			return false;
		}

		con::printMsg(std::format("unhooked {}\n", h->name()));
	}

	if (MH_Uninitialize() != MH_OK) {
		con::printErr("failed to uninitialize minhook\n");
		return false;
	}

	if (!Renderer::uninit()) {
		con::printErr("failed to uninitialize renderer\n");
		return false;
	}

	return true;
}

void Core::entry()
{
	con::alloc("rdrh");

	if (load())
	{
		con::printOke("loaded\n");

		while (!GetAsyncKeyState(VK_F11)) {
			Sleep(100);
		}
	}

	unload();

	Sleep(100);

	con::printOke("unloaded\n");

	con::free();
}
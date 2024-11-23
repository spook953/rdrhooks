#pragma once

#include "../sdk/sdk.hpp"

class App final
{
private:
	static bool load();
	static bool unload();

public:
	static void entry();
};
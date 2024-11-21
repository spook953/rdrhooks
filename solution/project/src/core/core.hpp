#pragma once

#include "../sdk/sdk.hpp"

class Core final
{
private:
	static bool load();
	static bool unload();

public:
	static void entry();
};
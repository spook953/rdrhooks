#pragma once

#include "../shared/shared.hpp"

class Core final
{
private:
	static bool load();
	static bool unload();

public:
	static void entry();
};
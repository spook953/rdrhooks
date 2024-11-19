#pragma once

#include <Windows.h>
#include <iostream>
#include <format>
#include <sstream>
#include <chrono>

namespace con
{
	void alloc(std::string_view name);
	void free();
}

namespace con
{
	void printMsg(std::string_view str);
	void printOke(std::string_view str);
	void printWrn(std::string_view str);
	void printErr(std::string_view str);
}
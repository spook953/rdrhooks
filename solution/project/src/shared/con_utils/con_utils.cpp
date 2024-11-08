#include "con_utils.hpp"

static std::string con_name{};

void setColors(const int colors)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colors);
}

void resetColors()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

std::string getTimeStamp()
{
	const std::chrono::system_clock::time_point now{ std::chrono::system_clock::now() };
	const std::time_t current_time{ std::chrono::system_clock::to_time_t(now) };

	std::tm local_time{};

	localtime_s(&local_time, &current_time);

	std::ostringstream oss{};

	oss << std::setw(2) << std::setfill('0') << local_time.tm_hour << ":"
		<< std::setw(2) << std::setfill('0') << local_time.tm_min << ":"
		<< std::setw(2) << std::setfill('0') << local_time.tm_sec;

	return oss.str();
}

void printStr(std::string_view str)
{
	std::cout << std::format("[{}] [{}] {}\n", con_name, getTimeStamp(), str);
}

void con::alloc(std::string_view name)
{
	con_name = name;

	AllocConsole();
	SetConsoleTitleA(con_name.c_str());

	static FILE *fp{};

	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONOUT$", "w", stderr);
	freopen_s(&fp, "CONIN$", "r", stdin);

	std::cout.clear();
	std::cerr.clear();
	std::cin.clear();

	std::ios::sync_with_stdio();
}

void con::free()
{
	FreeConsole();
}

void con::printMsg(std::string_view str)
{
	setColors(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printStr(str);
	resetColors();
}

void con::printWrn(std::string_view str)
{
	setColors(FOREGROUND_RED | FOREGROUND_GREEN);
	printStr(str);
	resetColors();
}

void con::printErr(std::string_view str)
{
	setColors(FOREGROUND_RED);
	printStr(str);
	resetColors();
}
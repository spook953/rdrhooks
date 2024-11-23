#pragma once

#include "../../rdr2/rdr2.hpp"

class Input final
{
private:
	class Key
	{
	public:
		bool pressed{};
		bool held{};
		bool released{};
	};

	class Wheel
	{
	public:
		bool up{};
		bool down{};
	};

	enum KeyState
	{
		NONE,
		PRESSED,
		HELD,
		RELEASED
	};

private:
	static inline bool key_states[256]{};
	static inline KeyState key_kstates[256]{};
	static inline int mouse_wheel_delta_cached{};
	static inline int mouse_wheel_delta{};
	static inline int mouse_pos_x{};
	static inline int mouse_pos_y{};
	static inline char key_char{};

public:
	static Key getKey(const size_t key);
	static char getChar();
	static Wheel getMouseWheel();
	static rdr2::Vector2 getMousePos();

public:
	static void wndproc(const UINT msg, const WPARAM wparam, const LPARAM lparam);

public:
	static void start();
	static void end();
};
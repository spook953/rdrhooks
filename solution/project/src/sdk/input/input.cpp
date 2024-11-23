#include "input.hpp"

Input::Key Input::getKey(const size_t key)
{
	Key out{};

	if (key >= 256) {
		return out;
	}

	if (key_kstates[key] == PRESSED) {
		out.pressed = true;
		out.held = true;
	}

	if (key_kstates[key] == HELD) {
		out.held = true;
	}

	if (key_kstates[key] == RELEASED) {
		out.released = true;
	}

	return out;
}

char Input::getChar()
{
	return key_char;
}

Input::Wheel Input::getMouseWheel()
{
	Wheel out{};

	if (mouse_wheel_delta > 0) {
		out.up = true;
	}

	if (mouse_wheel_delta < 0) {
		out.down = true;
	}

	return out;
}

rdr2::Vector2 Input::getMousePos()
{
	return { static_cast<float>(mouse_pos_x), static_cast<float>(mouse_pos_y) };
}

void Input::wndproc(const UINT msg, const WPARAM wparam, const LPARAM lparam)
{
	if (msg == WM_LBUTTONDOWN || msg == WM_LBUTTONDBLCLK) {
		key_states[VK_LBUTTON] = true;
	}

	if (msg == WM_LBUTTONUP) {
		key_states[VK_LBUTTON] = false;
	}

	if (msg == WM_RBUTTONDOWN || msg == WM_RBUTTONDBLCLK) {
		key_states[VK_RBUTTON] = true;
	}

	if (msg == WM_RBUTTONUP) {
		key_states[VK_RBUTTON] = false;
	}

	if (msg == WM_MBUTTONDOWN || msg == WM_MBUTTONDBLCLK) {
		key_states[VK_MBUTTON] = true;
	}

	if (msg == WM_MBUTTONUP) {
		key_states[VK_MBUTTON] = false;
	}

	if (msg == WM_XBUTTONDOWN || msg == WM_XBUTTONDBLCLK)
	{
		if (HIWORD(wparam) == XBUTTON1) {
			key_states[VK_XBUTTON1] = true;
		}

		if (HIWORD(wparam) == XBUTTON2) {
			key_states[VK_XBUTTON2] = true;
		}
	}

	if (msg == WM_XBUTTONUP)
	{
		if (HIWORD(wparam) == XBUTTON1) {
			key_states[VK_XBUTTON1] = false;
		}

		if (HIWORD(wparam) == XBUTTON2) {
			key_states[VK_XBUTTON2] = false;
		}
	}

	bool regular_key{};

	if (msg == WM_KEYDOWN) {
		key_states[wparam] = true;
		regular_key = true;
	}

	if (msg == WM_KEYUP) {
		key_states[wparam] = false;
		regular_key = true;
	}

	if (!regular_key)
	{
		if (msg == WM_SYSKEYDOWN) {
			key_states[wparam] = true;
		}

		if (msg == WM_SYSKEYUP) {
			key_states[wparam] = false;
		}
	}

	if (msg == WM_MOUSEWHEEL) {
		mouse_wheel_delta_cached += GET_WHEEL_DELTA_WPARAM(wparam);
	}

	if (msg == WM_MOUSEMOVE) {
		mouse_pos_x = LOWORD(lparam);
		mouse_pos_y = HIWORD(lparam);
	}

	if (msg == WM_CHAR) {
		key_char = static_cast<char>(wparam);
	}
}

void Input::start()
{
	for (size_t n{}; n < 256; n++)
	{
		if (key_states[n])
		{
			if (key_kstates[n] == PRESSED) {
				key_kstates[n] = HELD;
			}

			else if (key_kstates[n] != HELD) {
				key_kstates[n] = PRESSED;
			}
		}

		else
		{
			if (key_kstates[n] == RELEASED) {
				key_kstates[n] = NONE;
			}

			if (key_kstates[n] == PRESSED || key_kstates[n] == HELD) {
				key_kstates[n] = RELEASED;
			}
		}
	}

	mouse_wheel_delta = mouse_wheel_delta_cached;
	mouse_wheel_delta_cached = 0;
}

void Input::end()
{
	key_char = 0;
}
#pragma once

#include "imgui/imgui_impl_win32.hpp"
#include "imgui/imgui_impl_dx12.hpp"

#include "minhook/minhook.hpp"

#include <d3d12.h>
#include <dxgi1_4.h>

#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
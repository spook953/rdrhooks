#pragma once

#include "../../rdr2/rdr2.hpp"

class Renderer final
{
private:
	struct FrameContext final
	{
		ID3D12CommandAllocator *cmd_alloc{};
		ID3D12Resource *main_rt_rsrc{};
		D3D12_CPU_DESCRIPTOR_HANDLE main_rt_desc{};
	};

private:
	static inline HWND wnd{};
	static inline UINT frame_buf_count{};
	static inline std::vector<FrameContext> frame_ctx{};
	static inline ID3D12DescriptorHeap *srv_desc_heap{};
	static inline ID3D12DescriptorHeap *rtv_desc_heap{};
	static inline ID3D12GraphicsCommandList *cmd_list{};

private:
	static inline bool initialized{};

public:
	static bool init();
	static bool uninit();

public:
	static bool start();
	static void end();
};
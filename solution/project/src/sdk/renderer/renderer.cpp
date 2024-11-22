#include "renderer.hpp"

bool Renderer::init()
{
	if (initialized) {
		return true;
	}

	IDXGISwapChain *const swap_chain{ sigs::IDXGISwapChain_ptr.rcast<IDXGISwapChain *>() };

	if (!swap_chain) {
		return false;
	}

	ID3D12CommandQueue *const cmd_queue{ sigs::ID3D12CommandQueue_ptr.rcast<ID3D12CommandQueue *>() };

	if (!cmd_queue) {
		return false;
	}

	ID3D12Device *device{};

	if (swap_chain->GetDevice(__uuidof(ID3D12Device), reinterpret_cast<void **>(&device)) != S_OK) {
		return false;
	}

	DXGI_SWAP_CHAIN_DESC sc_desc{};
	{
		swap_chain->GetDesc(&sc_desc);

		wnd = sc_desc.OutputWindow;
		frame_buf_count = sc_desc.BufferCount;

		frame_ctx.clear();
		frame_ctx.resize(frame_buf_count);
	}

	D3D12_DESCRIPTOR_HEAP_DESC srv_desc{};
	{
		srv_desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
		srv_desc.NumDescriptors = frame_buf_count;
		srv_desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

		if (device->CreateDescriptorHeap(&srv_desc, IID_PPV_ARGS(&srv_desc_heap)) != S_OK) {
			return false;
		}
	}

	D3D12_DESCRIPTOR_HEAP_DESC rtv_desc{};
	{
		rtv_desc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
		rtv_desc.NumDescriptors = frame_buf_count;
		rtv_desc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
		rtv_desc.NodeMask = 1;

		if (device->CreateDescriptorHeap(&rtv_desc, IID_PPV_ARGS(&rtv_desc_heap)) != S_OK) {
			return false;
		}

		const UINT desc_size{ device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV) };

		D3D12_CPU_DESCRIPTOR_HANDLE rtv_handle{ rtv_desc_heap->GetCPUDescriptorHandleForHeapStart() };

		for (UINT n{}; n < frame_buf_count; n++) {
			frame_ctx[n].main_rt_desc = rtv_handle;
			swap_chain->GetBuffer(n, IID_PPV_ARGS(&frame_ctx[n].main_rt_rsrc));
			device->CreateRenderTargetView(frame_ctx[n].main_rt_rsrc, nullptr, rtv_handle);
			rtv_handle.ptr += desc_size;
		}
	}

	for (size_t n{}; n < frame_buf_count; n++)
	{
		if (device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&frame_ctx[n].cmd_alloc)) != S_OK) {
			return false;
		}
	}

	if (device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, frame_ctx[0].cmd_alloc, 0, IID_PPV_ARGS(&cmd_list)) != S_OK) {
		return false;
	}

	if (cmd_list->Close() != S_OK) {
		return false;
	}

	if (!ImGui::CreateContext()) {
		return false;
	}

	ImGui::GetIO().IniFilename = nullptr;
	ImGui::StyleColorsDark();

	if (!ImGui_ImplWin32_Init(wnd)) {
		return false;
	}

	if (!ImGui_ImplDX12_Init(
		device,
		frame_buf_count,
		DXGI_FORMAT_R8G8B8A8_UNORM,
		srv_desc_heap,
		srv_desc_heap->GetCPUDescriptorHandleForHeapStart(),
		srv_desc_heap->GetGPUDescriptorHandleForHeapStart())) {
		return false;
	}

	initialized = true;

	return true;
}

bool Renderer::uninit()
{
	if (!initialized) {
		return true;
	}

	ImGui_ImplDX12_Shutdown();
	ImGui_ImplWin32_Shutdown();

	ImGui::DestroyContext();

	wnd = 0;
	frame_buf_count = 0;

	for (FrameContext &fc : frame_ctx)
	{
		if (fc.cmd_alloc) {
			fc.cmd_alloc->Release();
			fc.cmd_alloc = nullptr;
		}

		if (fc.main_rt_rsrc) {
			fc.main_rt_rsrc->Release();
			fc.main_rt_rsrc = nullptr;
		}

		fc.main_rt_desc = {};
	}

	frame_ctx.clear();

	if (srv_desc_heap) {
		srv_desc_heap->Release();
		srv_desc_heap = nullptr;
	}

	if (rtv_desc_heap) {
		rtv_desc_heap->Release();
		rtv_desc_heap = nullptr;
	}

	if (cmd_list) {
		cmd_list->Release();
		cmd_list = nullptr;
	}

	initialized = false;

	return true;
}

bool Renderer::start()
{
	if (!initialized) {
		return false;
	}

	ImGui_ImplWin32_NewFrame();
	ImGui_ImplDX12_NewFrame();

	ImGui::NewFrame();

	return true;
}

void Renderer::end()
{
	if (!initialized) {
		return;
	}

	IDXGISwapChain3 *const swap_chain{ sigs::IDXGISwapChain_ptr.rcast<IDXGISwapChain3 *>() };

	if (!swap_chain) {
		return;
	}

	ID3D12CommandQueue *const cmd_queue{ sigs::ID3D12CommandQueue_ptr.rcast<ID3D12CommandQueue *>() };

	if (!cmd_queue) {
		return;
	}

	FrameContext &cur_frame_ctx{ frame_ctx[swap_chain->GetCurrentBackBufferIndex()] };

	cur_frame_ctx.cmd_alloc->Reset();

	D3D12_RESOURCE_BARRIER barrier{};
	{
		barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
		barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
		barrier.Transition.pResource = cur_frame_ctx.main_rt_rsrc;
		barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
		barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
		barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;
	}

	cmd_list->Reset(cur_frame_ctx.cmd_alloc, nullptr);
	cmd_list->ResourceBarrier(1, &barrier);
	cmd_list->OMSetRenderTargets(1, &cur_frame_ctx.main_rt_desc, 0, nullptr);
	cmd_list->SetDescriptorHeaps(1, &srv_desc_heap);

	ImGui::EndFrame();
	ImGui::Render();

	ImGui_ImplDX12_RenderDrawData(ImGui::GetDrawData(), cmd_list);

	barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
	barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;

	cmd_list->ResourceBarrier(1, &barrier);
	cmd_list->Close();

	cmd_queue->ExecuteCommandLists(1, reinterpret_cast<ID3D12CommandList **>(&cmd_list));
}
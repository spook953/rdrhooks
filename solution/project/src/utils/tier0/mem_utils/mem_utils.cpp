#include "mem_utils.hpp"

MemAddr mem::findBytes(std::string_view dll, std::string_view bytes)
{
	auto sigToBytes = [](const char *const sig) -> std::vector<int>
	{
		std::vector<int> bytes{};

		char *const start{ const_cast<char *>(sig) };
		char *const end{ const_cast<char *>(sig) + strlen(sig) };

		for (char *current{ start }; current < end; ++current)
		{
			if (*current == '?')
			{
				++current;

				if (*current == '?') {
					++current;
				}

				bytes.push_back(-1);
			}

			else {
				bytes.push_back(strtoul(current, &current, 16));
			}
		}

		return bytes;
	};

	const HMODULE hmod{ GetModuleHandleA(dll.data()) };

	if (!hmod) {
		return {};
	}

	MODULEINFO mod_info{};

	if (!K32GetModuleInformation(GetCurrentProcess(), hmod, &mod_info, sizeof(MODULEINFO))) {
		return {};
	}

	const DWORD image_size{ mod_info.SizeOfImage };

	if (!image_size) {
		return {};
	}

	const std::vector<int> pattern_bytes{ sigToBytes(bytes.data()) };
	const byte *const image_bytes{ reinterpret_cast<byte *>(hmod) };
	const size_t signature_size{ pattern_bytes.size() };
	const int *signature_bytes{ pattern_bytes.data() };

	for (unsigned long i{}; i < image_size - signature_size; ++i)
	{
		bool byte_sequence_found{ true };

		for (unsigned long j{}; j < signature_size; ++j)
		{
			if (image_bytes[i + j] != signature_bytes[j] && signature_bytes[j] != -1) {
				byte_sequence_found = false;
				break;
			}
		}

		if (byte_sequence_found) {
			return reinterpret_cast<uintptr_t>(&image_bytes[i]);
		}
	}

	return {};
}

MemAddr mem::findExport(std::string_view dll, std::string_view fn)
{
	const HMODULE hmod{ GetModuleHandleA(dll.data()) };
	
	if (!hmod) {
		return {};
	}
	
	return reinterpret_cast<uintptr_t>(GetProcAddress(hmod, fn.data()));
}

MemAddr mem::findVirtual(void *const vtable, const size_t vidx)
{
	return reinterpret_cast<uintptr_t>((*static_cast<void ***>(vtable))[vidx]);
}
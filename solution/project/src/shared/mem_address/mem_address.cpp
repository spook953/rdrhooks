#include "mem_address.hpp"

MemAddr::MemAddr(const uintptr_t addr)
{
	m_addr = addr;
}

MemAddr::MemAddr(void *const addr)
{
	m_addr = reinterpret_cast<uintptr_t>(addr);
}

MemAddr &MemAddr::operator=(const MemAddr &other)
{
	if (this != &other) {
		m_addr = other.m_addr;
	}

	return *this;
}

MemAddr MemAddr::operator+(const MemAddr &other) const
{
	return { m_addr + other.m_addr };
}

MemAddr MemAddr::operator-(const MemAddr &other) const
{
	return { m_addr - other.m_addr };
}

std::strong_ordering MemAddr::operator<=>(const MemAddr &other) const
{
	return m_addr <=> other.m_addr;
}

bool MemAddr::operator==(const MemAddr &other) const
{
	return m_addr == other.m_addr;
}

MemAddr::operator bool() const
{
	return m_addr > 0;
}

uintptr_t MemAddr::get() const
{
	return m_addr;
}

void MemAddr::set(const uintptr_t addr)
{
	m_addr = addr;
}

MemAddr MemAddr::offset(const size_t offset)
{
	if (m_addr) {
		m_addr += offset;
	}

	return *this;
}

MemAddr MemAddr::deref(size_t count)
{
	uintptr_t out{ m_addr };

	while (out && count > 0)
	{
		out = *reinterpret_cast<uintptr_t*>(out);

		if (!out) {
			return m_addr;
		}

		count--;
	}

	m_addr = out;

	return *this;
}

MemAddr MemAddr::fixRip(const size_t offset)
{
	if (m_addr && offset)
	{
		uintptr_t base{ m_addr + offset };

		const int32_t rip_address{ *reinterpret_cast<int32_t *>(base) };

		base += 4 + rip_address;

		m_addr = base;
	}

	return *this;
}
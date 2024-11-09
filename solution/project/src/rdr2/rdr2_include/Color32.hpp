#pragma once

#include "base.hpp"

namespace rdr2
{
	class Color32
	{
	public:
		uint8_t b{};
		uint8_t g{};
		uint8_t r{};
		uint8_t a{};

	public:
		Color32() = default;

		Color32(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255)
			: r(red), g(green), b(blue), a(alpha) {}

		Color32(int32_t red, int32_t green, int32_t blue, int32_t alpha = 255)
			: r(static_cast<uint8_t>(red)), g(static_cast<uint8_t>(green)), b(static_cast<uint8_t>(blue)), a(static_cast<uint8_t>(alpha)) {}

	public:
		bool operator==(const Color32 &other) const
		{
			return r == other.r && g == other.g && b == other.b && a == other.a;
		}

		Color32 &operator+=(const Color32 &other)
		{
			r = static_cast<uint8_t>(std::min(static_cast<uint32_t>(r) + other.r, static_cast<uint32_t>(255)));
			g = static_cast<uint8_t>(std::min(static_cast<uint32_t>(g) + other.g, static_cast<uint32_t>(255)));
			b = static_cast<uint8_t>(std::min(static_cast<uint32_t>(b) + other.b, static_cast<uint32_t>(255)));
			a = static_cast<uint8_t>(std::min(static_cast<uint32_t>(a) + other.a, static_cast<uint32_t>(255)));

			return *this;
		}

		Color32 &operator-=(const Color32 &other)
		{
			r = static_cast<uint8_t>(std::max(static_cast<int32_t>(r) - other.r, 0));
			g = static_cast<uint8_t>(std::max(static_cast<int32_t>(g) - other.g, 0));
			b = static_cast<uint8_t>(std::max(static_cast<int32_t>(b) - other.b, 0));
			a = static_cast<uint8_t>(std::max(static_cast<int32_t>(a) - other.a, 0));

			return *this;
		}

		Color32 operator-(const Color32 &other) const
		{
			Color32 result{ *this };

			result -= other;

			return result;
		}

		Color32 operator+(const Color32 &other) const
		{
			Color32 result{ *this };

			result += other;

			return result;
		}

		Color32 &operator=(const Color32 &other)
		{
			if (this != &other) {
				r = other.r;
				g = other.g;
				b = other.b;
				a = other.a;
			}

			return *this;
		}

	public:
		uint32_t GetARGB() const
		{
			return (static_cast<uint32_t>(a) << 24) | (static_cast<uint32_t>(r) << 16) | (static_cast<uint32_t>(g) << 8) | static_cast<uint32_t>(b);
		}
	};
}
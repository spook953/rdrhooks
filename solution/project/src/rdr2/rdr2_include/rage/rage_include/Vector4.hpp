/*
	Plugin-SDK (Grand Theft Auto IV) header file
	Authors: GTA Community. See more here
	https://github.com/DK22Pac/plugin-sdk
	Do not delete this comment block. Respect others' work!
*/

#pragma once

#include "../../../../shared/shared.hpp"

namespace rage
{
	class Vector4
	{
	public:
		float x{};
		float y{};
		float z{};
		float w{};

	public:
		Vector4() = default;
		Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

	public:
		bool operator==(const Vector4 &other) const
		{
			return x == other.x && y == other.y && z == other.z && w == other.w;
		}

		bool operator!=(const Vector4 &other) const
		{
			return !(*this == other);
		}

	public:
		Vector4 operator+(const Vector4 &other) const
		{
			return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
		}

		Vector4 operator-(const Vector4 &other) const
		{
			return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
		}

		Vector4 operator*(const float scalar) const
		{
			return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
		}

		Vector4 operator+(const float scalar) const
		{
			return Vector4(x + scalar, y + scalar, z + scalar, w + scalar);
		}

		Vector4 operator-(const float scalar) const
		{
			return Vector4(x - scalar, y - scalar, z - scalar, w - scalar);
		}

		friend Vector4 operator*(const float scalar, const Vector4 &vec)
		{
			Vector4 result{};

			result.x = vec.x * scalar;
			result.y = vec.y * scalar;
			result.z = vec.z * scalar;
			result.w = vec.w * scalar;

			return result;
		}

		Vector4 operator/(const float scalar) const
		{
			return Vector4(x / scalar, y / scalar, z / scalar, w / scalar);
		}

		Vector4 &operator=(const Vector4 &other)
		{
			if (this != &other)
			{
				x = other.x;
				y = other.y;
				z = other.z;
				w = other.w;
			}

			return *this;
		}

		Vector4 &operator+=(const Vector4 &other)
		{
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;

			return *this;
		}

		Vector4 &operator-=(const Vector4 &other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;

			return *this;
		}

	public:
		float Heading() const
		{
			return atan2f(-x, y);
		}

		float Magnitude()
		{
			return sqrt(x * x + y * y + z * z + w * w);
		}

		void Translate(const float x, const float y, const float z, const float w)
		{
			this->x += x;
			this->y += y;
			this->z += z;
			this->w += w;
		}

		void Translate(const float x, const float y)
		{
			this->x += x;
			this->y += y;
			this->z += x;
			this->w += y;
		}
	};
}
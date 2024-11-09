#pragma once

#include "base.hpp"

namespace rdr2
{
	class Vector3
	{
	public:
		float x{};
		float y{};
		float z{};

	public:
		Vector3() = default;
		Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

	public:
		bool operator==(const Vector3 &other) const
		{
			return x == other.x && y == other.y && z == other.z;
		}

		bool operator!=(const Vector3 &other) const
		{
			return !(*this == other);
		}

	public:
		Vector3 operator+(const Vector3 &other) const
		{
			return Vector3(x + other.x, y + other.y, z + other.z);
		}

		Vector3 operator-(const Vector3 &other) const
		{
			return Vector3(x - other.x, y - other.y, z - other.z);
		}

		Vector3 operator*(const float scalar) const
		{
			return Vector3(x * scalar, y * scalar, z * scalar);
		}

		Vector3 operator/(const float scalar) const
		{
			return Vector3(x / scalar, y / scalar, z / scalar);
		}

		Vector3 &operator=(const Vector3 &other)
		{
			if (this != &other) {
				x = other.x;
				y = other.y;
				z = other.z;
			}

			return *this;
		}

		Vector3 &operator+=(const Vector3 &other)
		{
			x += other.x;
			y += other.y;
			z += other.z;

			return *this;
		}

		Vector3 &operator+=(const float scalar)
		{
			x += scalar;
			y += scalar;
			z += scalar;

			return *this;
		}

		Vector3 &operator-=(const Vector3 &other)
		{
			x -= other.x;
			y -= other.y;
			z -= other.z;

			return *this;
		}

		Vector3 &operator*=(const Vector3 &other)
		{
			x *= other.x;
			y *= other.y;
			z *= other.z;

			return *this;
		}

	public:
		float Heading() const
		{
			return atan2f(-x, y);
		}

		float Magnitude()
		{
			return sqrt(x * x + y * y + z * z);
		}

		void Translate(const float x, const float y, const float z)
		{
			this->x += x;
			this->y += y;
			this->z += z;
		}
	};
}
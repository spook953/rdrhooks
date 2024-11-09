#pragma once

#include "base.hpp"

namespace rdr2
{
	class Vector2
	{
	public:
		float x{};
		float y{};

	public:
		Vector2() = default;
		Vector2(float x, float y) : x(x), y(y) {}

	public:
		bool operator==(const Vector2 &other) const
		{
			return x == other.x && y == other.y;
		}

		bool operator!=(const Vector2 &other) const
		{
			return !(*this == other);
		}

	public:
		Vector2 operator+(const Vector2 &other) const
		{
			return Vector2(x + other.x, y + other.y);
		}

		Vector2 operator-(const Vector2 &other) const
		{
			return Vector2(x - other.x, y - other.y);
		}

		Vector2 operator*(const float scalar) const
		{
			return Vector2(x * scalar, y * scalar);
		}

		Vector2 operator/(const float scalar) const
		{
			return Vector2(x / scalar, y / scalar);
		}

		Vector2 &operator=(const Vector2 &other)
		{
			if (this != &other) {
				x = other.x;
				y = other.y;
			}

			return *this;
		}

		Vector2 &operator+=(const Vector2 &other)
		{
			x += other.x;
			y += other.y;

			return *this;
		}

		Vector2 &operator-=(const Vector2 &other)
		{
			x -= other.x;
			y -= other.y;

			return *this;
		}

		Vector2 &operator*=(const float scalar)
		{
			x *= scalar;
			y *= scalar;

			return *this;
		}

	public:
		float Heading() const
		{
			return atan2f(-x, y);
		}

		float Magnitude()
		{
			return sqrt(x * x + y * y);
		}

		void Translate(const float x, const float y)
		{
			this->x += x;
			this->y += y;
		}
	};
}
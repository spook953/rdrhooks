#pragma once

#include "base.hpp"

#include "Vector3.hpp"

namespace rdr2
{
	class Matrix34
	{
	public:
		Vector3 right{};
		Vector3 up{};
		Vector3 at{};
		Vector3 pos{};

	public:
		Vector3 &GetPosition()
		{
			return pos;
		}

		Vector3 &GetRight()
		{
			return right;
		}

		Vector3 &GetForward()
		{
			return at;
		}

		Vector3 &GetUp()
		{
			return up;
		}

	public:
		const Vector3 &GetPosition() const
		{
			return pos;
		}

		const Vector3 &GetRight() const
		{
			return right;
		}

		const Vector3 &GetForward() const
		{
			return at;
		}

		const Vector3 &GetUp() const
		{
			return up;
		}

	public:
		Matrix34() = default;

	public:
		void Copy(const Matrix34 &other)
		{
			right = other.right;
			up = other.up;
			at = other.at;
			pos = other.pos;
		}

	public:
		Matrix34 operator+(const Matrix34 &other) const
		{
			Matrix34 result{};

			result.right = right + other.right;
			result.up = up + other.up;
			result.at = at + other.at;
			result.pos = pos + other.pos;

			return result;
		}

		Matrix34 operator-(const Matrix34 &other) const
		{
			Matrix34 result{};

			result.right = right - other.right;
			result.up = up - other.up;
			result.at = at - other.at;
			result.pos = pos - other.pos;

			return result;
		}

		Matrix34 &operator=(const Matrix34 &other)
		{
			if (this != &other) {
				right = other.right;
				up = other.up;
				at = other.at;
				pos = other.pos;
			}

			return *this;
		}

		Matrix34 &operator+=(const Matrix34 &other)
		{
			right += other.right;
			up += other.up;
			at += other.at;
			pos += other.pos;

			return *this;
		}

		Matrix34 &operator-=(const Matrix34 &other)
		{
			right -= other.right;
			up -= other.up;
			at -= other.at;
			pos -= other.pos;

			return *this;
		}

		Vector3 operator*(const Vector3 &vec) const
		{
			Vector3 result{};

			result.x = right.x * vec.x + up.x * vec.y + at.x * vec.z + pos.x;
			result.y = right.y * vec.x + up.y * vec.y + at.y * vec.z + pos.y;
			result.z = right.z * vec.x + up.z * vec.y + at.z * vec.z + pos.z;

			return result;
		}
	};
}
#pragma once

#include "Math.hpp"
#include "Matrix34.hpp"
#include "Vector4.hpp"
#include "Quaternion.hpp"

namespace rdr2
{
	class Matrix44
	{
	public:
		Vector4 right{};
		Vector4 up{};
		Vector4 at{};
		Vector4 pos{};

	public:
		Vector4 &GetPosition()
		{
			return pos;
		}

		Vector4 &GetRight()
		{
			return right;
		}

		Vector4 &GetForward()
		{
			return up;
		}

		Vector4 &GetUp()
		{
			return at;
		}

	public:
		const Vector4 &GetPosition() const
		{
			return pos;
		}

		const Vector4 &GetRight() const
		{
			return right;
		}

		const Vector4 &GetForward() const
		{
			return up;
		}

		const Vector4 &GetUp() const
		{
			return at;
		}

	public:
		Matrix44() = default;

	public:
		void Copy(const Matrix44 &other)
		{
			right = other.right;
			up = other.up;
			at = other.at;
			pos = other.pos;
		}

		void Copy(const Matrix44 *other)
		{
			right = other->right;
			up = other->up;
			at = other->at;
			pos = other->pos;
		}

	public:
		Matrix44 operator+(const Matrix44 &other) const
		{
			Matrix44 result{};

			result.right = right + other.right;
			result.up = up + other.up;
			result.at = at + other.at;
			result.pos = pos + other.pos;

			return result;
		}

		Matrix44 operator-(const Matrix44 &other) const
		{
			Matrix44 result{};

			result.right = right - other.right;
			result.up = up - other.up;
			result.at = at - other.at;
			result.pos = pos - other.pos;

			return result;
		}

		Matrix44 &operator=(const Matrix44 &other)
		{
			if (this != &other) {
				right = other.right;
				up = other.up;
				at = other.at;
				pos = other.pos;
			}

			return *this;
		}

		Matrix44 &operator+=(const Matrix44 &other)
		{
			right += other.right;
			up += other.up;
			at += other.at;
			pos += other.pos;

			return *this;
		}

		Matrix44 &operator-=(const Matrix44 &other)
		{
			right -= other.right;
			up -= other.up;
			at -= other.at;
			pos -= other.pos;

			return *this;
		}

		Matrix44 operator*(const Matrix44 &other) const
		{
			Matrix44 result{};

			result.right.x = this->right.x * other.right.x + this->right.y * other.up.x + this->right.z * other.at.x;
			result.right.y = this->right.x * other.right.y + this->right.y * other.up.y + this->right.z * other.at.y;
			result.right.z = this->right.x * other.right.z + this->right.y * other.up.z + this->right.z * other.at.z;

			result.up.x = this->up.x * other.right.x + this->up.y * other.up.x + this->up.z * other.at.x;
			result.up.y = this->up.x * other.right.y + this->up.y * other.up.y + this->up.z * other.at.y;
			result.up.z = this->up.x * other.right.z + this->up.y * other.up.z + this->up.z * other.at.z;

			result.at.x = this->at.x * other.right.x + this->at.y * other.up.x + this->at.z * other.at.x;
			result.at.y = this->at.x * other.right.y + this->at.y * other.up.y + this->at.z * other.at.y;
			result.at.z = this->at.x * other.right.z + this->at.y * other.up.z + this->at.z * other.at.z;

			result.pos.x = this->pos.x * other.right.x + this->pos.y * other.up.x + this->pos.z * other.at.x + other.pos.x;
			result.pos.y = this->pos.x * other.right.y + this->pos.y * other.up.y + this->pos.z * other.at.y + other.pos.y;
			result.pos.z = this->pos.x * other.right.z + this->pos.y * other.up.z + this->pos.z * other.at.z + other.pos.z;

			return result;
		}

		void operator*=(const Matrix44 &other)
		{
			float tmp_x{};
			float tmp_y{};
			float tmp_z{};

			tmp_x = this->right.x * other.right.x + this->right.y * other.up.x + this->right.z * other.at.x;
			tmp_y = this->right.x * other.right.y + this->right.y * other.up.y + this->right.z * other.at.y;
			tmp_z = this->right.x * other.right.z + this->right.y * other.up.z + this->right.z * other.at.z;

			right = { tmp_x, tmp_y, tmp_z, 0.0f };

			tmp_x = this->up.x * other.right.x + this->up.y * other.up.x + this->up.z * other.at.x;
			tmp_y = this->up.x * other.right.y + this->up.y * other.up.y + this->up.z * other.at.y;
			tmp_z = this->up.x * other.right.z + this->up.y * other.up.z + this->up.z * other.at.z;

			up = { tmp_x, tmp_y, tmp_z, 0.0f };

			tmp_x = this->at.x * other.right.x + this->at.y * other.up.x + this->at.z * other.at.x;
			tmp_y = this->at.x * other.right.y + this->at.y * other.up.y + this->at.z * other.at.y;
			tmp_z = this->at.x * other.right.z + this->at.y * other.up.z + this->at.z * other.at.z;

			at = { tmp_x, tmp_y, tmp_z, 0.0f };

			tmp_x = this->pos.x * other.right.x + this->pos.y * other.up.x + this->pos.z * other.at.x + other.pos.x;
			tmp_y = this->pos.x * other.right.y + this->pos.y * other.up.y + this->pos.z * other.at.y + other.pos.y;
			tmp_z = this->pos.x * other.right.z + this->pos.y * other.up.z + this->pos.z * other.at.z + other.pos.z;

			pos = { tmp_x, tmp_y, tmp_z, 1.0f };
		}

		void SetRotate(const Vector3 &angle)
		{
			const float cx{ cos(angle.x) };
			const float sx{ sin(angle.x) };
			const float cy{ cos(angle.y) };
			const float sy{ sin(angle.y) };
			const float cz{ cos(angle.z) };
			const float sz{ sin(angle.z) };

			right.x = cz * cy - (sz * sx) * sy;
			right.y = (cz * sx) * sy + sz * cy;
			right.z = -cx * sy;

			up.x = -sz * cx;
			up.y = cz * cx;
			up.z = sx;

			at.x = (sz * sx) * cy + cz * sy;
			at.y = sz * sy - (cz * sx) * cy;
			at.z = cx * cy;
		}

	public:
		Quaternion MatrixToQuaternion() const
		{
			const float trace{ right.x + up.y + at.z };

			float qx{};
			float qy{};
			float qz{};
			float qw{};

			if (trace > 0.0f)
			{
				const float s{ sqrt(trace + 1.0f) * 2.0f };

				qw = 0.25f * s;
				qx = (up.z - at.y) / s;
				qy = (at.x - right.z) / s;
				qz = (right.y - up.x) / s;
			}

			else if (right.x > up.y && right.x > at.z)
			{
				const float s{ sqrt(1.0f + right.x - up.y - at.z) * 2.0f };

				qw = (up.z - at.y) / s;
				qx = 0.25f * s;
				qy = (up.x + right.y) / s;
				qz = (at.x + right.z) / s;
			}

			else if (up.y > at.z)
			{
				const float s{ sqrt(1.0f + up.y - right.x - at.z) * 2.0f };

				qw = (at.x - right.z) / s;
				qx = (up.x + right.y) / s;
				qy = 0.25f * s;
				qz = (at.y + up.z) / s;
			}

			else
			{
				const float s{ sqrt(1.0f + at.z - right.x - up.y) * 2.0f };

				qw = (right.y - up.x) / s;
				qx = (at.x + right.z) / s;
				qy = (at.y + up.z) / s;
				qz = 0.25f * s;
			}

			return Quaternion(qx, qy, qz, qw);
		}

		Vector3 QuaternionToEulerAngles(const Quaternion &quat) const
		{
			Vector3 angles{};

			const float sinr_cosp{ 2.0f * (quat.w * quat.x + quat.y * quat.z) };
			const float cosr_cosp{ 1.0f - 2.0f * (quat.x * quat.x + quat.y * quat.y) };

			angles.x = atan2(sinr_cosp, cosr_cosp);

			const float sinp{ 2.0f * (quat.w * quat.y - quat.z * quat.x) };

			if (fabs(sinp) >= 1.0f) {
				angles.y = copysign(pi() / 2.0f, sinp);
			}

			else {
				angles.y = asin(sinp);
			}

			const float siny_cosp{ 2.0f * (quat.w * quat.z + quat.x * quat.y) };
			const float cosy_cosp{ 1.0f - 2.0f * (quat.y * quat.y + quat.z * quat.z) };

			angles.z = atan2(siny_cosp, cosy_cosp);

			return angles;
		}

		Vector3 GetRotation() const
		{
			const Quaternion quat{ MatrixToQuaternion() };

			return QuaternionToEulerAngles(quat);
		}

	public:
		Matrix34 As34() const
		{
			Matrix34 out{};

			out.right = { right.x, right.y, right.z };
			out.up = { up.x, up.y, up.z };
			out.at = { at.x, at.y, at.z };
			out.pos = { pos.x, pos.y, pos.z };

			return out;
		}
	};
}
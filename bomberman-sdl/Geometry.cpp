#include "pch.h"

#include "Geometry.h"

Vector2::Vector2(float X, float Y) : x(X), y(Y) {};

Vector2 Vector2::operator+(Vector2 a) const { return Vector2(x + a.x, y + a.y); }
Vector2 Vector2::operator-(Vector2 a) const { return Vector2(x - a.x, y - a.y); }
Vector2 Vector2::operator*(float a) const { return Vector2(x*a, y*a); }
Vector2 Vector2::operator/(float a) const { return Vector2(x / a, y / a); }

bool Vector2::operator==(Vector2 a) const { return (a.x == x && a.y == y); }
bool Vector2::operator!=(Vector2 a) const { return (a.x != x || a.y != y); }

void Vector2::Set(float X, float Y) { x = X; y = Y; }

float Vector2::Magnitude() { return std::sqrtf(SqrMagnitude()); }
float Vector2::SqrMagnitude() { return x * x + y * y; }

float Vector2::Dot(Vector2&a, Vector2&b) { return a.x*b.x + a.y*b.y; }

Vector2 Vector2::PositiveRotateBy90(Vector2 vec) { return Vector2(-vec.y, vec.x); }
Vector2 Vector2::NegativeRotateBy90(Vector2 vec) { return Vector2(vec.y, -vec.x); }

const Vector2 Vector2::Zero = Vector2(0, 0);
const Vector2 Vector2::Half = Vector2(.5, .5);
const Vector2 Vector2::One = Vector2(1, 1);

//====================================================================================================//

void AABB::Verify()
{
	Vector2 _min, _max;

	_min.x = std::min(min.x, max.x);
	_min.y = std::min(min.y, max.y);

	_max.x = std::max(min.x, max.x);
	_max.y = std::max(min.y, max.y);

	min = _min;
	max = _max;
}

float Clamp(float v, float min, float max)
{
	return (v < min) ? min : (v > max) ? max : v;
}

bool Intersect(float a1, float b1, float a2, float b2)
{
	return a2 < b1 && a1 < b2;
}

bool Intersect(AABB & a, AABB & b)
{
	return	Intersect(a.min.x, a.max.x, b.min.x, b.max.x) &&
			Intersect(a.min.y, a.max.y, b.min.y, b.max.y);
}

bool IsInsideBox(AABB&box, Vector2&origin)
{
	return
		box.min.x < origin.x && origin.x < box.max.x &&
		box.min.y < origin.y && origin.y < box.max.y;
}

Vector2 NearestPointInBox(AABB&box, Vector2&origin)
{
	return Vector2(
		Clamp(origin.x, box.min.x, box.max.x),
		Clamp(origin.y, box.min.y, box.max.y));
}
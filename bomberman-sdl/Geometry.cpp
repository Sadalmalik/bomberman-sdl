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

float Vector2::Dot(Vector2&a, Vector2&b) { return a.x*b.x + a.y*b.y; }

Vector2 Vector2::PositiveRotateBy90(Vector2 vec) { return Vector2(-vec.y, vec.x); }
Vector2 Vector2::NegativeRotateBy90(Vector2 vec) { return Vector2(vec.y, -vec.x); }

const Vector2 Vector2::Zero = Vector2(0, 0);
const Vector2 Vector2::Half = Vector2(.5, .5);
const Vector2 Vector2::One = Vector2(1, 1);
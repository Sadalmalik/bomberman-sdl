#pragma once

#pragma pack(push)
#pragma pack(1)

class Vector2
{
public:
	float x;
	float y;

	Vector2(float X=0, float Y=0);

	Vector2 operator+(Vector2 a) const;
	Vector2 operator-(Vector2 a) const;

	Vector2 operator*(float a) const;
	Vector2 operator/(float a) const;

	bool operator==(Vector2 a) const;
	bool operator!=(Vector2 a) const;

	void Set(float X, float Y);

	static float Dot(Vector2&a, Vector2&b);

	static Vector2 PositiveRotateBy90(Vector2 vec);
	static Vector2 NegativeRotateBy90(Vector2 vec);

	static const Vector2 Zero, Half, One;
};

#pragma pack(pop)
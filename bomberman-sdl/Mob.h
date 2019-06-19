#pragma once

#include "Geometry.h"

class Mob
{
public:
	Vector2 position;

	virtual void Update() = 0;
	virtual void Render(SDL_Renderer*rend) = 0;
};
#pragma once

#include "Geometry.h"

class GameObject
{
public:
	bool active = true;

	Vector2 position;
	int zIndex = 0;

	virtual void Init(SDL_Renderer*rend) = 0;
	virtual void Update() = 0;
	virtual void Render(SDL_Renderer*rend) = 0;
	virtual void Dispose() = 0;
};
#pragma once

#include "pch.h"

class Image
{
public:
	virtual ~Image() {}

	virtual void Render(SDL_Renderer*rend, SDL_Rect& rect) = 0;
};
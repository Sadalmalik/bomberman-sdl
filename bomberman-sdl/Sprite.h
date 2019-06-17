#pragma once
#pragma once

#include "pch.h"
#include "GameObject.h"

#include "TileImage.h"
#include "AnimatedImage.h"

class Sprite : public GameObject
{
	Image*_image;
	int _w, _h;
public:
	Sprite(Image *image, int w, int h);
	~Sprite();

	void Init(SDL_Renderer*rend);
	void Update();
	void Render(SDL_Renderer*rend);
	void Dispose();
};
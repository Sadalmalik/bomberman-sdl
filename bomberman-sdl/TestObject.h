#pragma once

#include "functions.h"
#include "GameObject.h"

class TileSet;
class AnimatedImage;

class TestObject : public GameObject
{
	int angle = 0;
	float speedA = 0.57f;
	float speedB = 1.31f;
	SDL_Texture *image = nullptr;

	TileSet *tileSet = nullptr;
	AnimatedImage *anim = nullptr;

	SDL_Rect rect;
public:
	TestObject();

	void Init(SDL_Renderer*rend);
	void Update();
	void Render(SDL_Renderer*rend);
	void Dispose();
};


#pragma once

#include "functions.h"
#include "GameObject.h"

class TestObject : public GameObject
{
	int angle = 0;
	float speed = 0.5f;
	SDL_Texture *image = NULL;

	SDL_Rect tile;
	SDL_Rect rect;
public:
	TestObject();

	void Init(SDL_Renderer*rend);
	void Update();
	void Render(SDL_Renderer*rend);
	void Dispose();
};


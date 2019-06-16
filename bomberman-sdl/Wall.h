#pragma once

#include "pch.h"
#include "GameObject.h"

#include "TileImage.h"
#include "AnimatedImage.h"

enum WallType
{
	brick=0,
	hard,
	side
};

class Wall : public GameObject
{
	TileImage*_image;
	AnimatedImage*_destroyAnimation;
public:
	Wall(WallType type = WallType::brick);
	~Wall();

	void Destroy();

	void Init(SDL_Renderer*rend);
	void Update();
	void Render(SDL_Renderer*rend);
	void Dispose();
};
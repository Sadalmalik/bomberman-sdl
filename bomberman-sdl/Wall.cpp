#include "pch.h"

#include "functions.h"
#include "Wall.h"
#include "BombermanAssets.h"

//Image*_image;
//AnimatedImage*_destroyAnimation;

Wall::Wall(WallType type) :
	_image(nullptr),
	_destroyAnimation(nullptr)
{
	switch (type)
	{
	case brick:
		_image = BombermanAssets::CreateWall();
		break;
	case hard:
		_image = BombermanAssets::CreateHardWall();
		break;
	case side:
		_image = BombermanAssets::CreateSideWall();
		break;
	default:
		throw std::invalid_argument("Wrong WallType value!");
		break;
	}
}

Wall::~Wall()
{

}

void Wall::Destroy()
{
	_destroyAnimation = BombermanAssets::CreateWallDestroyAnimation();

}

void Wall::Init(SDL_Renderer*rend)
{

}

void Wall::Update()
{
	if (_destroyAnimation &&
		_destroyAnimation->Complete())
		this->active = false;
}

void Wall::Render(SDL_Renderer*rend)
{
	SDL_Rect rect;
	SetupRect(&rect, position.x, position.y-32, 32, 64);
	if (_destroyAnimation)
		_destroyAnimation->Render(rend, rect);
	else _image->Render(rend, rect);
}

void Wall::Dispose()
{
	delete _image;
	delete _destroyAnimation;
}
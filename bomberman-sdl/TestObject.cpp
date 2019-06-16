#include "pch.h"

#include "TestObject.h"
#include "TileSet.h"
#include "AnimatedImage.h"
#include "BombermanAssets.h"

TestObject::TestObject()
{
	zIndex = 1;
}

void TestObject::Init(SDL_Renderer*rend)
{
	anim = BombermanAssets::CreateWallDestroyAnimation();

	SetupRect(&rect, 0, 0, 2 * 16, 2 * 32);
}

void TestObject::Update()
{
	angle++;

	float a = angle * Deg2Rad;
	position.x = 250 * (1 + std::cos(a * speedA));
	position.y = 250 * (1 + std::sin(a * speedB));
}

void TestObject::Render(SDL_Renderer*rend)
{
	rect.x = static_cast<int>(position.x);
	rect.y = static_cast<int>(position.y);

	anim->Render(rend, rect);
}

void TestObject::Dispose()
{
	delete anim;
}
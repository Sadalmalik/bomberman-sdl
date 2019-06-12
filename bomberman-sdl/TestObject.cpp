#include "pch.h"

#include "TestObject.h"
#include "TileSet.h"
#include "AnimatedImage.h"

TestObject::TestObject()
{
}

void TestObject::Init(SDL_Renderer*rend)
{
	printf("\nTestObject::Init <%16x>", (unsigned long long int)rend);
	image = loadTexture("Tileset.png", rend);

	tileSet = new TileSet(image, 16, 32);
	anim = new AnimatedImage(tileSet, 0, 8, true);

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
	delete tileSet;

	SDL_DestroyTexture(image);
	image = nullptr;
}
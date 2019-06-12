#include "pch.h"

#include "TestObject.h"

TestObject::TestObject()
{
}

void TestObject::Init(SDL_Renderer*rend)
{
	printf("\nTestObject::Init <%08x>", rend);
	image = loadTexture("Tileset.png", rend);

	SetupRect(&tile, 0, 6 * 16, 16, 32);
	SetupRect(&rect, 0, 0, 4 * 16, 4 * 32);
}

void TestObject::Update()
{
	printf("\nTestObject::Update");
	angle++;

	float a = angle * speed * Deg2Rad;
	position.x = 50 + 50 * std::cos(a);
	position.y = 50 + 50 * std::sin(a);
}

void TestObject::Render(SDL_Renderer*rend)
{
	printf("\nTestObject::Render");
	printf("\nDraw test object at %d %d", position.x, position.y);

	rect.x = static_cast<int>(position.x);
	rect.y = static_cast<int>(position.y);
	SDL_RenderCopy(rend, image, &tile, &rect);
}

void TestObject::Dispose()
{
	printf("\nTestObject::Dispose");
	SDL_DestroyTexture(image);
	image = nullptr;
}
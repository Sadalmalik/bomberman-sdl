#include "pch.h"

#include "Sprite.h"
#include "functions.h"

Sprite::Sprite(Image *image, int w, int h) :
	_image(image), _w(w), _h(h)
{}

Sprite::~Sprite()
{
}

void Sprite::Init(SDL_Renderer*rend)
{

}

void Sprite::Update()
{

}

void Sprite::Render(SDL_Renderer*rend)
{
	SDL_Rect rect;
	SetupRect(&rect, position.x, position.y, _w, _h);
	_image->Render(rend, rect);
}

void Sprite::Dispose()
{
	delete _image;
}
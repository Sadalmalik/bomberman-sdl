#pragma once

#include "Image.h"
#include "TileSet.h"

class TileImage : public Image
{
	int _index;
	TileSet*_tileset;
public:
	TileImage(TileSet*set, int index);
	~TileImage();

	void Render(SDL_Renderer*rend, SDL_Rect& rect);
};
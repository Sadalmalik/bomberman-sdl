#pragma once

#include "Image.h"
#include "TileSet.h"

class AnimatedImage : public Image
{
	int _start;
	int _end;
	TileSet*_tileset;
	int _idx;
public:
	bool loop;
	bool complete;

	AnimatedImage(TileSet*set, int start, int end, bool loop = true);
	~AnimatedImage();

	void Render(SDL_Renderer*rend, SDL_Rect& rect);
};

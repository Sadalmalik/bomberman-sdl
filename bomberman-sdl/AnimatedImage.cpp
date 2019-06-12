#include "pch.h"

#include "AnimatedImage.h"

AnimatedImage::AnimatedImage(TileSet*set, int start, int end, bool loop) :
	_start(start),
	_end(end),
	_tileset(set),
	_idx(start),
	loop(loop)
{
	complete = false;
}

AnimatedImage::~AnimatedImage()
{

}

void AnimatedImage::Render(SDL_Renderer*rend, SDL_Rect& rect)
{
	if (_idx >= _end)
	{
		if (loop)
			_idx = _start;
		else
			complete = true;
	}
	if (complete) return;
	_tileset->DrawTile(rend, _idx++, rect);
}
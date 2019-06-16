#include "pch.h"

#include "functions.h"
#include "AnimatedImage.h"

AnimatedImage::AnimatedImage(TileSet*set, int start, int end, bool loop) :
	_start(start),
	_end(end),
	_tileset(set),
	_endTime(0),
	loop(loop)
{
	_duration = 1000;
	Start();
}

AnimatedImage::~AnimatedImage()
{

}

void AnimatedImage::SetDuration(Uint32 duration)
{
	_duration = duration;
}

bool AnimatedImage::Complete()
{
	return _endTime < SDL_GetTicks();
}

void AnimatedImage::Start()
{
	_endTime = SDL_GetTicks() + _duration;
}

void AnimatedImage::Render(SDL_Renderer*rend, SDL_Rect& rect)
{
	if (!loop && Complete()) return;

	Uint32 time = SDL_GetTicks();
	while (_endTime < time)
		_endTime += _duration;

	float frame = (_duration - (_endTime - time)) / 1000.0f;
	int idx = clamp((int)((_end - _start) * frame), _start, _end);

	_tileset->DrawTile(rend, idx, rect);
}
#pragma once

#include "Image.h"
#include "TileSet.h"

class AnimatedImage : public Image
{
	int _start;
	int _end;
	TileSet*_tileset;
	Uint32 _endTime;
	Uint32 _duration;
public:
	bool loop;

	AnimatedImage(TileSet*set, int startFrame, int endFrame, bool loop = true);
	~AnimatedImage();

	void SetDuration(Uint32 duration);
	bool Complete();
	void Start();

	void Render(SDL_Renderer*rend, SDL_Rect& rect);
};

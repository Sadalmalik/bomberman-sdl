#include "pch.h"

#include "TileImage.h"

TileImage::TileImage(TileSet*ts, int index) : _index(index), _tileset(ts)
{
}

TileImage::~TileImage()
{

}

void TileImage::Render(SDL_Renderer*rend, SDL_Rect& rect)
{
	_tileset->DrawTile(rend, _index, rect);
}
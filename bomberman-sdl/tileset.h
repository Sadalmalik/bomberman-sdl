#pragma once

#include "pch.h"

class TileSet
{
	int tileXSize;
	int tileYSize;
	int textureXSize;
	int textureYSize;
	int tilesXCount;
	int tilesYCount;
	SDL_Texture*texture;
public:
	TileSet(SDL_Texture*texture, int tileXSize, int tileYSize);

	void GetTileRect(SDL_Rect&rect, int tile);
	void CalculateRect(SDL_Rect&rect, int x, int y);

	void DrawTile(SDL_Renderer*renderer, int tile, SDL_Rect&rect);
};
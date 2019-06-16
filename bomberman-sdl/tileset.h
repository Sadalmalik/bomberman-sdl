#pragma once

#include "pch.h"

class TileSet
{
	SDL_Texture*_texture;
public:
	int tileXSize;
	int tileYSize;
	int textureXSize;
	int textureYSize;
	int tilesXCount;
	int tilesYCount;
	int tilesCount;

	TileSet(SDL_Texture*texture, int tileXSize, int tileYSize);

	SDL_Texture* GetTexture() const;
	void GetTileRect(SDL_Rect&rect, int tile) const;
	void CalculateRect(SDL_Rect&rect, int x, int y) const;

	void DrawTile(SDL_Renderer*renderer, int tile, SDL_Rect&rect);
};
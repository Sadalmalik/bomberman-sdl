#pragma once

#include <SDL.h>

class Tileset
{
	int tileXSize;
	int tileYSize;
	int textureXSize;
	int textureYSize;
	SDL_Texture*texture;
public:
	Tileset(SDL_Texture*texture, int x, int y);

	void GetTileRect(SDL_Rect&rect, int tile);
	void CalculateRect(SDL_Rect&rect, int x, int y);

	void DrawTile(SDL_Renderer*renderer, int tile, SDL_Rect&rect);
};
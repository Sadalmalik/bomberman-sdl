#include "pch.h"

#include "functions.h"
#include "Tileset.h"

Tileset::Tileset(SDL_Texture*tex, int x, int y)
{
	tileXSize = x;
	tileYSize = y;
	texture = tex;
	SDL_QueryTexture(tex, NULL, NULL, &textureXSize, &textureYSize);
}

void Tileset::GetTileRect(SDL_Rect&rect, int tile)
{
	SetupRect(&rect,
		tile % tileXSize,
		tile / tileXSize,
		tileXSize,
		tileYSize);
}

void Tileset::CalculateRect(SDL_Rect&rect, int x, int y)
{
	SetupRect(&rect,
		x * tileXSize,
		y * tileYSize,
		tileXSize,
		tileYSize);
}

void Tileset::DrawTile(SDL_Renderer*renderer, int tile, SDL_Rect&rect)
{
	SDL_Rect tileRect;
	GetTileRect(tileRect, tile);
	SDL_RenderCopy(renderer, texture, &tileRect, &rect);
}
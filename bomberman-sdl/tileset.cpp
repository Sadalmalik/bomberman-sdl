#include "pch.h"

#include "functions.h"
#include "Tileset.h"

TileSet::TileSet(SDL_Texture*tex, int tileXSize, int tileYSize)
{
	this->tileXSize = tileXSize;
	this->tileYSize = tileYSize;
	texture = tex;
	SDL_QueryTexture(tex, NULL, NULL, &textureXSize, &textureYSize);
	tilesXCount = textureXSize / tileXSize;
	tilesYCount = textureYSize / tileYSize;
}

void TileSet::GetTileRect(SDL_Rect&rect, int tile)
{
	int x = tile % tilesXCount;
	int y = tile / tilesXCount;
	SetupRect(&rect,
		x * tileXSize,
		y * tileXSize,
		tileXSize,
		tileYSize);
}

void TileSet::CalculateRect(SDL_Rect&rect, int x, int y)
{
	SetupRect(&rect,
		x * tileXSize,
		y * tileYSize,
		tileXSize,
		tileYSize);
}

void TileSet::DrawTile(SDL_Renderer*renderer, int tile, SDL_Rect&rect)
{
	SDL_Rect tileRect;
	GetTileRect(tileRect, tile);
	SDL_RenderCopy(renderer, texture, &tileRect, &rect);
}
#include "pch.h"

#include "functions.h"
#include "BombermanAssets.h"

#include "TileSet.h"
#include "AnimatedImage.h"
#include "TileImage.h"

int BombermanAssets::mobRadius = 16;
int BombermanAssets::screenTileXSize = 32;
int BombermanAssets::screenTileYSize = 32;

SDL_Texture* BombermanAssets::texture;
TileSet* BombermanAssets::tileset;
TileSet* BombermanAssets::tilesetDouble;

void BombermanAssets::Init(SDL_Renderer*renderer)
{
	texture = loadTexture("Assets/Tileset.png", renderer);

	tileset = new TileSet(texture, 16, 16);
	tilesetDouble = new TileSet(texture, 16, 32);
}

void BombermanAssets::Dispose()
{
	SDL_DestroyTexture(tileset->GetTexture());
	SDL_DestroyTexture(tilesetDouble->GetTexture());

	delete tileset;
	delete tilesetDouble;
}

TileImage* BombermanAssets::CreateGrass()
{
	return new TileImage(tileset, 16*7 + 3);
}

TileImage* BombermanAssets::CreateWall()
{
	return new TileImage(tilesetDouble, 16 * 3 + 0);
}

TileImage* BombermanAssets::CreateHardWall()
{
	return new TileImage(tilesetDouble, 16 * 3 + 1);
}

TileImage* BombermanAssets::CreateSideWall()
{
	return new TileImage(tilesetDouble, 16 * 3 + 2);
}

AnimatedImage* BombermanAssets::CreateWallDestroyAnimation()
{
	return new AnimatedImage(tilesetDouble, 0, 8, 800, false);
}

AnimatedImage* BombermanAssets::CreateMobDeathAnimation()
{
	int frame = 16 * 0; // line
	return new AnimatedImage(tileset, frame+8, frame + 16);
}

AnimatedImage* BombermanAssets::CreateMob1Animation()
{
	int frame = 16 * 1;
	return new AnimatedImage(tileset, frame + 8, frame + 16);
}

AnimatedImage* BombermanAssets::CreateMob2Animation()
{
	int frame = 16 * 2;
	return new AnimatedImage(tileset, frame + 8, frame + 16);
}

AnimatedImage* BombermanAssets::CreateMob3Animation()
{
	int frame = 16 * 3;
	return new AnimatedImage(tileset, frame + 8, frame + 16);
}

AnimatedImage* BombermanAssets::CreateEnlightAnimation()
{
	int frame = 16 * 2;
	return new AnimatedImage(tileset, frame, frame+8);
}

AnimatedImage* BombermanAssets::CreateBombAnimation()
{
	int frame = 16 * 3;
	return new AnimatedImage(tileset, frame, frame + 8);
}

AnimatedImage* BombermanAssets::CreateExplosionAnimation()
{
	int frame = 16 * 4;
	return new AnimatedImage(tileset, frame, frame + 8, 600, false);
}

AnimatedImage* BombermanAssets::CreatePortalAnimation()
{
	int frame = 16 * 5;
	return new AnimatedImage(tileset, frame, frame + 8);
}

AnimatedImage* BombermanAssets::CreatePlayerDownAnimation()
{
	int frame = 16 * 4;
	return new AnimatedImage(tilesetDouble, frame, frame + 8);
}

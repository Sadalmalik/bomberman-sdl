#include "pch.h"

#include "functions.h"
#include "BombermanAssets.h"

#include "TileSet.h"
#include "AnimatedImage.h"
#include "TileImage.h"

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
	return new AnimatedImage(tilesetDouble, 0, 8, true);
}

AnimatedImage* BombermanAssets::CreateMobDeathAnimation()
{
	int frame = 16 * 0; // line
	return new AnimatedImage(tileset, frame+8, frame + 16, true);
}

AnimatedImage* BombermanAssets::CreateMob1Animation()
{
	int frame = 16 * 1;
	return new AnimatedImage(tileset, frame + 8, frame + 16, true);
}

AnimatedImage* BombermanAssets::CreateMob2Animation()
{
	int frame = 16 * 2;
	return new AnimatedImage(tileset, frame + 8, frame + 16, true);
}

AnimatedImage* BombermanAssets::CreateMob3Animation()
{
	int frame = 16 * 3;
	return new AnimatedImage(tileset, frame + 8, frame + 16, true);
}

AnimatedImage* BombermanAssets::CreateEnlightAnimation()
{
	int frame = 16 * 2;
	return new AnimatedImage(tileset, frame, frame+8, true);
}

AnimatedImage* BombermanAssets::CreateBombAnimation()
{
	int frame = 16 * 3;
	return new AnimatedImage(tileset, frame, frame + 8, true);
}

AnimatedImage* BombermanAssets::CreateExplosionAnimation()
{
	int frame = 16 * 4;
	return new AnimatedImage(tileset, frame, frame + 8, true);
}

AnimatedImage* BombermanAssets::CreatePortalAnimation()
{
	int frame = 16 * 5;
	return new AnimatedImage(tileset, frame, frame + 8, true);
}

AnimatedImage* BombermanAssets::CreatePlayerDownAnimation()
{
	int frame = 16 * 4;
	return new AnimatedImage(tilesetDouble, frame+8, frame + 8, true);
}

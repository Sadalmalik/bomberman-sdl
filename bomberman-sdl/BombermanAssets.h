#pragma once

#include "pch.h"

class AnimatedImage;
class TileImage;
class TileSet;

class BombermanAssets
{
public:
	static SDL_Texture* texture;
	static TileSet* tileset;
	static TileSet* tilesetDouble;	//	walls uses 2 tile height

	static void Init(SDL_Renderer*renderer);
	static void Dispose();

	static TileImage* CreateGrass();
	static TileImage* CreateWall();
	static TileImage* CreateHardWall();
	static TileImage* CreateSideWall();

	static AnimatedImage* CreateWallDestroyAnimation();

	static AnimatedImage* CreateMobDeathAnimation();
	static AnimatedImage* CreateMob1Animation();
	static AnimatedImage* CreateMob2Animation();
	static AnimatedImage* CreateMob3Animation();

	static AnimatedImage* CreateEnlightAnimation();
	static AnimatedImage* CreateBombAnimation();
	static AnimatedImage* CreateExplosionAnimation();
	static AnimatedImage* CreatePortalAnimation();

	static AnimatedImage* CreatePlayerDownAnimation();
};
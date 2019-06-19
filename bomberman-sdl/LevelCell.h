#pragma once

#include "Image.h"
#include "AnimatedImage.h"
#include "TileImage.h"

class Mob;

enum WallType
{
	regular, hard, border
};

class LevelCell
{
public:
	int x=0, y=0;
	bool passed = false;
	bool indestructible = false;

	Image*floor = nullptr;
	TileImage*wall = nullptr;
	AnimatedImage*fallWall = nullptr;
	AnimatedImage*explosion = nullptr;

	AnimatedImage*bomb = nullptr;
	int explosionTime = 0;
	int bombPower = 1;

	std::unordered_set<Mob*> mobs;

	LevelCell();
	~LevelCell();

	void Init(int x, int y);

	bool IsDamage();
	bool IsBlocked();
	bool IsBombTimeOut();

	void Update();

	void BuildWall(WallType type);
	void PlantBomb(int delay, int power);
	void BreakWall();
	void Explode();
};
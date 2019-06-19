#pragma once

#include "Array2D.h"

#include "Mob.h"
#include "LevelCell.h"

#include "ExplosionController.h"

class Level
{
	Array2D<LevelCell>_level;
public:
	int xOffset;
	int yOffset;
	int gridXSize;
	int gridYSize;
	int bombTime = 2500;

	//PathFinder*pathFinder;
	ExplosionController*explosionController;

	std::unordered_set<Mob*> mobs;

	Level(int x=0, int y=0);

	void LoadDefaultLevel();

	void LoadLevel(std::string file);

	void PlantBomd(int x, int y);
	void Explode(int x, int y, int power, MoveDirection direction = MoveDirection::None);

	void Init(SDL_Renderer*rend);
	void Update();
	void Render(SDL_Renderer*rend);
	void Dispose();

	friend class PathFinder;
	friend class ExplosionController;
};





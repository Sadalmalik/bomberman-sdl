#pragma once

#include "GameObject.h"
#include "Array2D.h"

class LevelCell
{
public:
	bool passed;
	bool damage;
	bool indestructible;
	GameObject*wall;
};

class Level : GameObject
{
	Array2D<LevelCell>_level;
public:
	Level();

	void CollidePlayer(GameObject*player, float radius);

	friend class PathFinder;
};

Level::Level() : _level(0, 0)
{
	zIndex = -1;
}

void Level::CollidePlayer(GameObject*player, float radius)
{

}






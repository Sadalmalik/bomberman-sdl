#pragma once

#include "GameObject.h"
#include "Array2D.h"
#include "Scene.h"
#include "TileImage.h"

class LevelCell
{
public:
	bool passed = false;
	bool damage = false;
	bool indestructible = false;
	GameObject*wall = nullptr;

	LevelCell();
	~LevelCell();
};

class Level : public GameObject
{
	Array2D<LevelCell>_level;
	Scene*_scene;
	TileImage*_grass;
public:
	int gridXSize;
	int gridYSize;

	Level();

	void LoadDefaultLevel();

	void LoadLevel(std::string file);

	void CollidePlayer(GameObject*player, float radius);

	void Init(SDL_Renderer*rend);
	void Update();
	void Render(SDL_Renderer*rend);
	void Dispose();

	friend class PathFinder;
};





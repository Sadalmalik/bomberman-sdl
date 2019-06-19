#pragma once

#include "MoveDirection.h"

class ExplosionNode
{
public:
	int x, y;
	MoveDirection direction;
	int power;

	ExplosionNode(int x, int y, int power, MoveDirection direction);

	bool Complete();
	void Step();
};

class Level;

class ExplosionController
{
	Level*_level;
	std::vector<ExplosionNode*>_explosions;
public:
	int currectPower = 4;

	ExplosionController(Level*level);
	~ExplosionController();

	void Explode(int x, int y, int power, MoveDirection direction = MoveDirection::None);

	void Init(SDL_Renderer*rend);
	void Update();
	void Render(SDL_Renderer*rend);
	void Dispose();
};
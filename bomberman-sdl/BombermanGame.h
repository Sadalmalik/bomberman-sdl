#pragma once

#include "GameManager.h"

#include "Level.h"
#include "Mob.h"

#include "Player.h"

class BombermanGame : public GameManager
{
	Level*_level;
	std::vector<Mob*>_mobs;
public:
	Player*player;

	void Init();
	void HandleEvent(SDL_Event&windowEvent);
	void Update();
	void Render(SDL_Renderer*rend);
	void Dispose();
};
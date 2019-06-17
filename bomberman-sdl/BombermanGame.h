#pragma once

#include "GameManager.h"

#include "TestObject.h"
#include "Level.h"

class BombermanGame : public GameManager
{
	size_t _limit = 25;
	int _delay = 0;
	std::vector<TestObject*>_test;
	Level*level;

public:
	void Init();
	void HandleEvent(SDL_Event&windowEvent);
	void Update();
	void Render(SDL_Renderer*rend);
	void Dispose();
};
#pragma once

#include "GameManager.h"

#include "TestObject.h"

class BombermanGameManager : public GameManager
{
	size_t _limit = 25;
	int _delay = 0;
	std::vector<TestObject*>_test;


public:
	void Init();
	void HandleEvent(SDL_Event&windowEvent);
	void Update();
	void Dispose();
};
#pragma once

#include "GameManager.h"

#include "TestObject.h"

class BombermanGameManager : public GameManager
{
	int _limit = 10;
	int _delay = 0;
	std::vector<TestObject*>_test;
public:
	void Init();
	void HandleEvent(SDL_Event&windowEvent);
	void Update();
	void Dispose();
};
#pragma once

#include "AnimatedImage.h"

#include "Mob.h"
#include "MoveDirection.h"

class Player : public Mob
{
	bool _keyLeft, _keyRight, _keyUp, _keyDown;
public:
	AnimatedImage*animDown = nullptr;
	float speed = 1.0f;
	bool plantingBomb = false;

	Player();
	~Player();

	void HandleEvents(SDL_Event&windowEvent);

	void Update();
	void Render(SDL_Renderer*rend);
};




#pragma once

#include "MoveDirection.h";

class PlayerInput
{
	bool _lastAxis;
	bool _keyLeft;
	bool _keyRight;
	bool _keyUp;
	bool _keyDown;
public:
	MoveDirection direction;

	PlayerInput();

	void HandleEvents(SDL_Event&windowEvent);
};
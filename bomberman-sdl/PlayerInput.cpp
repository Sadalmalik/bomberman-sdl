#include "pch.h"

#include "PlayerInput.h"

PlayerInput::PlayerInput()
{
	_lastAxis =
		_keyLeft =
		_keyRight =
		_keyUp =
		_keyDown = false;
}

void PlayerInput::HandleEvents(SDL_Event&windowEvent)
{

	switch (windowEvent.type)
	{
	case SDL_KEYDOWN:
		//windowEvent.key.keysym
		break;
	case SDL_KEYUP:
		break;
	default:
		break;
	}
}

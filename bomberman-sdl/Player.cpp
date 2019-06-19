#include "pch.h"

#include "functions.h"
#include "Player.h"
#include "BombermanAssets.h"

Player::Player()
{
	position.Set(0, 0);
	animDown = BombermanAssets::CreatePlayerDownAnimation();
}

Player::~Player()
{
	delete animDown;
}

//bool _keyLeft, _keyRight, _keyUp, _keyDown;
void Player::HandleEvents(SDL_Event&windowEvent)
{
	auto&key = windowEvent.key.keysym.sym;
	if (windowEvent.type == SDL_KEYDOWN)
	{
		if (key == SDLK_UP || key == SDLK_w)	_keyUp = true;
		if (key == SDLK_DOWN || key == SDLK_s)	_keyDown = true;
		if (key == SDLK_LEFT || key == SDLK_a)	_keyLeft = true;
		if (key == SDLK_RIGHT || key == SDLK_d)	_keyRight = true;

		if (key == SDLK_SPACE)	plantingBomb = true;
	}
	if (windowEvent.type == SDL_KEYUP)
	{
		if (key == SDLK_UP || key == SDLK_w)	_keyUp = false;
		if (key == SDLK_DOWN || key == SDLK_s)	_keyDown = false;
		if (key == SDLK_LEFT || key == SDLK_a)	_keyLeft = false;
		if (key == SDLK_RIGHT || key == SDLK_d)	_keyRight = false;

		if (key == SDLK_SPACE)	plantingBomb = false;
	}
}


void Player::Update()
{
	Vector2 velocity;
	velocity.x = (_keyLeft ? -1 : 0) + (_keyRight ? 1 : 0);
	velocity.y = (_keyUp ? -1 : 0) + (_keyDown ? 1 : 0);

	position = position + velocity * speed;
}

void Player::Render(SDL_Renderer*rend)
{
	SDL_Rect rect;
	SetupRect(&rect,
		(int)position.x, (int)position.y,
		BombermanAssets::screenTileXSize,
		BombermanAssets::screenTileYSize *2);
	animDown->Render(rend, rect);
}
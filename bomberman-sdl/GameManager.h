#pragma once

class Game;

class GameManager
{
protected:
	Game*_game;
public:

	virtual void Init() = 0;

	virtual void HandleEvent(SDL_Event&windowEvent) = 0;

	virtual void Update() = 0;

	virtual void Render(SDL_Renderer*rend) = 0;

	virtual void Dispose() = 0;

	friend class Game;
};
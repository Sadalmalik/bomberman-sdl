#pragma once

#include "Scene.h"
#include "GameManager.h"

class Game
{
	bool _isRunning = false;

	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = nullptr;
	Uint32 _start = 0;

	Scene* _scene = nullptr;
	GameManager* _gameManager = nullptr;

public:
	Uint32 targetFPS = 60;

	const int WIDTH = 800;
	const int HEIGHT = 600;

	Game();
	~Game();

	SDL_Renderer* GetRenderer() const;

	void SetWindowTitle(const char*title);
	void SetWindowSize(int width, int height);
	void SetWindowDisplayMode(const SDL_DisplayMode* mode);

	int Start(GameManager*gameManager=nullptr);

	int Init();

	void HandleEvents();
	void Update();
	void Render();

	void MainLoop();

	void Dispose();
};
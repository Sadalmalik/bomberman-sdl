#include "pch.h"

#include "functions.h"

#include "game.h"
#include "scene.h"
#include "BombermanAssets.h"

Game::Game() {}

Game::~Game() {}

SDL_Renderer * Game::GetRenderer() const
{
	return _renderer;
}

void Game::SetWindowTitle(const char*title)
{
	SDL_SetWindowTitle(_window, title);
}

void Game::SetWindowSize(int width, int height)
{
	SDL_SetWindowSize(_window, width, height);
}

void Game::SetWindowDisplayMode(const SDL_DisplayMode* mode)
{
	SDL_SetWindowDisplayMode(_window, mode);
}

int Game::Start(GameManager*gameManager)
{
	_gameManager = gameManager;
	int err = Init();

	if (err == 0)
	{
		MainLoop();

		Dispose();
	}

	return err;
}

int Game::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		LogSDLError("SDL could not initialise!");
		return EXIT_FAILURE;
	}

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		LogIMGError("Could not init image sistem");
		return EXIT_FAILURE;
	}

	_window = SDL_CreateWindow("Bomberman", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);

	if (_window == nullptr)
	{
		LogSDLError("Could not create window!");
		return EXIT_FAILURE;
	}

	_renderer = SDL_CreateRenderer(_window, -1, 0);

	return EXIT_SUCCESS;
}

void Game::HandleEvents()
{
	SDL_Event windowEvent;

	while (SDL_PollEvent(&windowEvent))
	{
		switch (windowEvent.type)
		{
		case SDL_QUIT:
		{
			_isRunning = false;
			break;
		}
		default:
		{
			if (_gameManager)
				_gameManager->HandleEvent(windowEvent);
			break;
		}
		}
	}
}

void Game::Update()
{
	if (_gameManager)
		_gameManager->Update();
	_scene->Update();
}

void Game::Render()
{
	SDL_SetRenderDrawColor(_renderer, 8, 8, 32, 255);
	SDL_RenderClear(_renderer);

	_gameManager->Render(_renderer);
	_scene->Render();

	SDL_RenderPresent(_renderer);
}

void Game::MainLoop()
{
	BombermanAssets::Init(_renderer);

	_scene = Scene::GetInstance();
	_scene->Init(_renderer);

	if (_gameManager)
	{
		_gameManager->_game = this;
		_gameManager->_scene = _scene;
		_gameManager->Init();
	}

	_isRunning = true;

	while (_isRunning)
	{
		_start = SDL_GetTicks();

		HandleEvents();
		Update();
		Render();

		if (1000 / targetFPS > SDL_GetTicks() - _start)
			SDL_Delay(1000 / targetFPS - (SDL_GetTicks() - _start));
	}

	if (_gameManager)
		_gameManager->Dispose();

	_scene->Dispose();

	BombermanAssets::Dispose();
}

void Game::Dispose()
{
	SDL_DestroyWindow(_window);
	SDL_Quit();
}
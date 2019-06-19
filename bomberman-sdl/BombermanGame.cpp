#include "pch.h"

#include "Game.h"
#include "BombermanGame.h"
#include "BombermanAssets.h"

void BombermanGame::Init()
{
	_game->SetWindowSize(
		20 + 15 * 32,
		60 + 15 * 32);

	_level = new Level(10,50);
	_level->LoadDefaultLevel();
	_level->Init(_game->GetRenderer());

	player = new Player();
	player->position.Set(10+32, 50+32);
	_level->mobs.insert(player);
}

void BombermanGame::HandleEvent(SDL_Event&windowEvent)
{
	player->HandleEvents(windowEvent);
}

void BombermanGame::Update()
{
	player->Update();

	if (player->plantingBomb)
		_level->PlantBomd(
			(int)player->position.x / BombermanAssets::screenTileXSize,
			(int)player->position.y / BombermanAssets::screenTileYSize);

	_level->Update();

	for (auto mob : _mobs)
		mob->Update();
}

void BombermanGame::Render(SDL_Renderer*rend)
{
	_level->Render(rend);

	//player->Render(rend);
}

void BombermanGame::Dispose()
{
	_level->Dispose();

	int len = _mobs.size();
	for (int i = 0; i < len; i++)
	{
		delete _mobs[i];
		_mobs[i] = nullptr;
	}
	_mobs.clear();
}
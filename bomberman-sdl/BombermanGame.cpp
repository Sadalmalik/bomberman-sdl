#include "pch.h"

#include "Game.h"
#include "BombermanGame.h"

void BombermanGame::Init()
{
	printf("BombermanGame::Init");

	level = new Level();
	level->LoadDefaultLevel();
	level->Init(_game->GetRenderer());
}

void BombermanGame::HandleEvent(SDL_Event&windowEvent)
{

}

void BombermanGame::Update()
{
	if (_test.size() < _limit)
	{
		_delay--;

		if (_delay <= 0)
		{
			TestObject*obj = new TestObject();
			_scene->AddObject(obj);
			_test.push_back(obj);

			_delay = 10;
		}
	}

	level->Update();
}

void BombermanGame::Render(SDL_Renderer*rend)
{
	level->Render(rend);
}

void BombermanGame::Dispose()
{
	printf("BombermanGame::Dispose");

	level->Dispose();

	for (auto obj : _test)
	{
		_scene->RemoveObject(obj);
		delete obj;
	}

	_test.clear();
}
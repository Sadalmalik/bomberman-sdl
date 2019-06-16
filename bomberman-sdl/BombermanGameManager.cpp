#include "pch.h"

#include "Game.h"
#include "BombermanGameManager.h"

void BombermanGameManager::Init()
{
	printf("BombermanGameManager::Init");

	level = new Level();
	level->LoadDefaultLevel();
	level->Init(_game->GetRenderer());
}

void BombermanGameManager::HandleEvent(SDL_Event&windowEvent)
{

}

void BombermanGameManager::Update()
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

void BombermanGameManager::Render(SDL_Renderer*rend)
{
	level->Render(rend);
}

void BombermanGameManager::Dispose()
{
	printf("BombermanGameManager::Dispose");

	level->Dispose();

	for (auto obj : _test)
	{
		_scene->RemoveObject(obj);
		delete obj;
	}

	_test.clear();
}
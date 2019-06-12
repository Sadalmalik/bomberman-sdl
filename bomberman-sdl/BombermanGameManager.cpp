#include "pch.h"

#include "BombermanGameManager.h"

void BombermanGameManager::Init()
{
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
			printf("Add test object!");
			TestObject*obj = new TestObject();
			_scene->AddObject(obj);
			_test.push_back(obj);

			_delay = 10;
		}
	}

}

void BombermanGameManager::Dispose()
{
	printf("BombermanGameManager::Dispose");

	for (auto obj : _test)
	{
		_scene->RemoveObject(obj);
		delete obj;
	}

	_test.clear();
}
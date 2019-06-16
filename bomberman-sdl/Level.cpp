#include "pch.h"

#include "functions.h"
#include "Level.h"
#include "BombermanAssets.h"
#include "Wall.h"

LevelCell::LevelCell() : wall(nullptr)
{
}

LevelCell::~LevelCell()
{
	delete wall;
}

Level::Level() : _level(0, 0)
{
	zIndex = -1;
	_scene = Scene::GetInstance();
}

void Level::LoadDefaultLevel()
{
	gridXSize = 15;
	gridYSize = 15;
	LevelCell def;
	_level.Resize(gridXSize, gridYSize);
	_level.Fill(def);
	for (int x = 0; x < gridXSize; x++)
		for (int y = 0; y < gridYSize; y++)
		{
			LevelCell& cell = _level.Get(x, y);

			if (x == 0 || x == gridXSize - 1 || y == 0 || y == gridYSize - 1)
			{
				//	Side walls
				cell.indestructible = true;
				cell.wall = new Wall(WallType::side);
			}
			else if ((x&1)==0 && (y&1)==0)
			{
				//	Inner walls
				cell.indestructible = true;
				cell.wall = new Wall(WallType::hard);
			}

			if (cell.wall)
			{
				_scene->AddObject(cell.wall);
				cell.wall->position.Set(x * 32, y * 32);
			}
		}
}

void Level::LoadLevel(std::string file)
{

}

void Level::CollidePlayer(GameObject*player, float radius)
{

}

void Level::Init(SDL_Renderer*rend)
{
	_grass = BombermanAssets::CreateGrass();
}

void Level::Update()
{

}

void Level::Render(SDL_Renderer*rend)
{
	if (_level.Length() == 0)
		return;
	SDL_Rect rect;
	SetupRect(&rect, 0, 0, 32, 32);
	for (int x = 0; x < gridXSize; x++)
		for (int y = 0; y < gridYSize; y++)
		{
			LevelCell& cell = _level.Get(x, y);

			SetupRect(&rect, x*32, y * 32, 32, 32);
			_grass->Render(rend, rect);

			if (cell.indestructible)
				continue;

			//if (cell.wall == nullptr ||
			//	!cell.wall->active)
			//	_grass->Render(rend, rect);
		}
}

void Level::Dispose()
{
	int len = _level.Length();
	for (int i = 0; i < len; i++)
	{
		LevelCell& cell = _level.Get(i);
		if (cell.wall)
			_scene->RemoveObject(cell.wall);
	}

	delete _grass;
}
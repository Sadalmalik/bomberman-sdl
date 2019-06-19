#include "pch.h"

#include "functions.h"
#include "Level.h"
#include "LevelCell.h"
#include "BombermanAssets.h"


Level::Level(int x, int y) : _level(0, 0), xOffset(x), yOffset(y)
{
	explosionController = new ExplosionController(this);
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

			cell.Init(x, y);

			if (x == 0 || x == gridXSize - 1 || y == 0 || y == gridYSize - 1)
			{
				cell.BuildWall(WallType::border);
			}
			else if ((x&1)==0 && (y&1)==0)
			{
				cell.BuildWall(WallType::hard);
			}
			else if (x > 2 || y > 2)
			{
				if (Random() < 0.3f)
					cell.BuildWall(WallType::regular);
			}
		}
}

void Level::LoadLevel(std::string file)
{

}

void Level::PlantBomd(int x, int y)
{
	if (!_level.ValidIndex(x, y)) return;
	LevelCell& cell = _level.Get(x, y);
	cell.PlantBomb(bombTime, explosionController->currectPower);
}

void Level::Explode(int x, int y, int power, MoveDirection direction)
{
}

void Level::Init(SDL_Renderer*rend)
{
}

void Level::Update()
{
	int len = _level.Length();
	for (int i = 0; i < len; i++)
	{
		LevelCell& cell = _level.Get(i);

		cell.Update();
		cell.mobs.clear();

		if (cell.IsBombTimeOut())
			explosionController->Explode(cell.x, cell.y, cell.bombPower);
	}

	explosionController->Update();

	int tileX = BombermanAssets::screenTileXSize;
	int tileY = BombermanAssets::screenTileYSize;
	int halfX = tileX / 2;
	int halfY = tileY / 2;

	for (auto mob : mobs)
	{
		mob->Update();
		int x = (int)(mob->position.x / tileX);
		int y = (int)(mob->position.y / tileY);
		LevelCell& cell = _level.Get(x, y);
		cell.mobs.insert(mob);

		float radius = BombermanAssets::mobRadius;
		AABB aabb;
		for (int ox = -1; ox < 2; ox++)
			for (int oy = -1; oy < 2; oy++)
			{
				if (ox == 0 && oy == 0)
					continue;
				int cx = x + ox;
				int cy = y + oy;
				if (!_level.ValidIndex(cx, cy)) continue;
				LevelCell& cell = _level.Get(cx, cy);
				if (cell.IsBlocked())
				{
					aabb.min.x = cell.x * tileX;
					aabb.min.y = cell.y * tileY;
					aabb.max.x = (cell.x + 1) * tileX;
					aabb.max.y = (cell.y + 1) * tileY;

					if (IsInsideBox(aabb, mob->position)) continue;

					Vector2 near = NearestPointInBox(aabb, mob->position);
					Vector2 delta = mob->position - near;
					float dist = delta.Magnitude();
					if (dist < 0.01f)
						continue;
					if (dist < radius)
					{
						delta = delta * (radius - dist) / dist;
						mob->position = mob->position + delta;
					}
				}
			}
	}
}

void Level::Render(SDL_Renderer*rend)
{
	if (_level.Length() == 0)
		return;

	SDL_Rect rect;
	int xSize = BombermanAssets::screenTileXSize;
	int ySize = BombermanAssets::screenTileYSize;

	for (int y = 0; y < gridYSize; y++)
		for (int x = 0; x < gridXSize; x++)
		{
			LevelCell& cell = _level.Get(x, y);

			SetupRect(&rect,
				x * xSize + xOffset,
				y * ySize + yOffset,
				xSize, ySize);
			if (cell.floor)		cell.floor->Render(rend, rect);
			if (cell.bomb)		cell.bomb->Render(rend, rect);
			if (cell.explosion)	cell.explosion->Render(rend, rect);
		}

	for (int y = 0; y < gridYSize; y++)
		for (int x = 0; x < gridXSize; x++)
		{
			LevelCell& cell = _level.Get(x, y);

			SetupRect(&rect,
				x * xSize + xOffset,
				(y-1) * ySize + yOffset,
				xSize, ySize * 2);
			if (cell.wall)		cell.wall->Render(rend, rect);
			if (cell.fallWall)	cell.fallWall->Render(rend, rect);

			for (auto mob : cell.mobs)
			{
				mob->Render(rend);
			}
			//if (cell.indestructible) continue;
		}
}

void Level::Dispose()
{
	_level.Resize(0,0);
}
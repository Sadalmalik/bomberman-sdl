#include "pch.h"

#include "LevelCell.h"
#include "BombermanAssets.h"

LevelCell::LevelCell()
{

}

LevelCell::~LevelCell()
{
	delete floor;
	delete wall;
	delete fallWall;
	delete explosion;
	delete bomb;
}

void LevelCell::Init(int _x, int _y)
{
	x = _x;
	y = _y;
	floor = BombermanAssets::CreateGrass();
}

bool LevelCell::IsDamage()
{
	return explosion || fallWall;
}

bool LevelCell::IsBlocked()
{
	return wall || bomb;
}

bool LevelCell::IsBombTimeOut()
{
	return bomb && explosionTime <= SDL_GetTicks();
}

void LevelCell::Update()
{
	if (explosion && explosion->Complete())
	{
		delete explosion;
		explosion = nullptr;
	}

	if (fallWall && fallWall->Complete())
	{
		delete fallWall;
		fallWall = nullptr;
	}


}

void LevelCell::BuildWall(WallType type)
{
	if (type == WallType::regular)
	{
		indestructible = false;
		wall = BombermanAssets::CreateWall();
	}

	if (type == WallType::hard)
	{
		indestructible = true;
		wall = BombermanAssets::CreateHardWall();
	}

	if (type == WallType::border)
	{
		indestructible = true;
		wall = BombermanAssets::CreateSideWall();
	}
}

void LevelCell::PlantBomb(int delay, int power)
{
	if (bomb == nullptr)
	{
		bomb = BombermanAssets::CreateBombAnimation();
		explosionTime = SDL_GetTicks() + delay;
		bombPower = power;
	}
}

void LevelCell::BreakWall()
{
	if (!indestructible)
	{
		delete wall;
		wall = nullptr;
		fallWall = BombermanAssets::CreateWallDestroyAnimation();
	}
}

void LevelCell::Explode()
{
	if (explosion==nullptr)
		explosion = BombermanAssets::CreateExplosionAnimation();
}
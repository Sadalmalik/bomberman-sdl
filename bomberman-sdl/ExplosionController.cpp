#include "pch.h"

#include "Level.h"
#include "LevelCell.h"
#include "ExplosionController.h"
#include "BombermanAssets.h"

ExplosionNode::ExplosionNode(int _x, int _y, int pow, MoveDirection dir)
{
	x = _x;
	y = _y;
	power = pow;
	direction = dir;
}

bool ExplosionNode::Complete()
{
	return power <= 0;
}

void ExplosionNode::Step()
{
	if (direction == MoveDirection::Up) y -= 1;
	if (direction == MoveDirection::Down) y += 1;
	if (direction == MoveDirection::Left) x -= 1;
	if (direction == MoveDirection::Right) x += 1;
	power--;
}



ExplosionController::ExplosionController(Level*level)
{
	_level = level;
}

ExplosionController::~ExplosionController()
{

}

void ExplosionController::Explode(int x, int y, int power, MoveDirection direction)
{
	if (x < 0 || _level->gridXSize < x || y < 0 || _level->gridYSize < y)
		return;
	LevelCell& cell = _level->_level.Get(x, y);
	if (cell.indestructible) return;
	if (cell.bomb)
	{
		delete cell.bomb; cell.bomb = nullptr;
	}

	cell.Explode();

	//	Don't send explosion back
	if (direction != MoveDirection::Up)
		_explosions.push_back(new ExplosionNode(x, y, power, MoveDirection::Down));

	if (direction != MoveDirection::Down)
		_explosions.push_back(new ExplosionNode(x, y, power, MoveDirection::Up));

	if (direction != MoveDirection::Left)
		_explosions.push_back(new ExplosionNode(x, y, power, MoveDirection::Right));

	if (direction != MoveDirection::Right)
		_explosions.push_back(new ExplosionNode(x, y, power, MoveDirection::Left));
}

void ExplosionController::Init(SDL_Renderer*rend)
{

}

void ExplosionController::Update()
{
	for (int i = _explosions.size() - 1; i >= 0; i--)
	{
		ExplosionNode*explosion = _explosions[i];
		explosion->Step();

		int x = explosion->x;
		int y = explosion->y;
		LevelCell& cell = _level->_level.Get(x, y);

		bool blocked = false;
		if (cell.bomb)
		{
			blocked = true;
			Explode(x, y, currectPower, explosion->direction);
		}

		if (cell.wall)
		{
			blocked = true;
			cell.BreakWall();
		}

		if (blocked || explosion->Complete())
		{
			_explosions.erase(_explosions.begin() + i);
		}
		else cell.Explode();
	}
}

void ExplosionController::Render(SDL_Renderer*rend)
{

}

void ExplosionController::Dispose()
{

}
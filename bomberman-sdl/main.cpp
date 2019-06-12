#include "pch.h"

#include "game.h"
#include "BombermanGameManager.h"


int main(int argsCount, char *args[])
{
	srand((Uint32)time(0));

	Game game;
	BombermanGameManager gameManager;

	int res = game.Start(&gameManager);
	int xx;

	std::cin >> xx;


	return res;
}
﻿#include "pch.h"

#include "game.h"
#include "BombermanGame.h"


int main(int argsCount, char *args[])
{
	srand((Uint32)time(0));

	Game game;
	BombermanGame gameManager;

	int res = game.Start(&gameManager);

	printf("Press any key to continue: ");
	char c;
	std::cin >> c;

	return res;
}
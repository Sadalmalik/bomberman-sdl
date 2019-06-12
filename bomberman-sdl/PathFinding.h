#pragma once

class LevelCell;

struct PathNode
{
	int x, y;
	bool valid;
	PathNode*next;
	LevelCell*cell;
};

PathNode* ReverseList(PathNode*head)
{
	PathNode*prev = nullptr;
	PathNode*next = nullptr;

	while (head->next)
	{
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	}

	head->next = prev;
	return head;
}

void DeletePath(PathNode*head)
{
	PathNode*next = nullptr;

	while (head->next)
	{
		next = head->next;
		delete head;
		head = next;
	}

	delete head;
}

class PathFinder
{
public:
	//PathNode*FindPath(Array2D<LevelCell>*level, int xStart, int yStart){}
};
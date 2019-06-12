#pragma once

#include "pch.h"
#include "GameObject.h"

class Scene
{
	SDL_Renderer*_renderer;
	std::vector<GameObject*>_objects;
public:
	Scene();
	~Scene();

	void AddObject(GameObject*object);
	void RemoveObject(GameObject*object);

	void Init(SDL_Renderer*renderer);
	void Update();
	void Render();
	void Dispose();
};
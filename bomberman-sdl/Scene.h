#pragma once

#include "pch.h"
#include "GameObject.h"

class Scene
{
	SDL_Renderer*_renderer;
	std::vector<GameObject*>_objects;

	Scene();
	~Scene();
public:
	static Scene* GetInstance();

	void AddObject(GameObject*object);
	void RemoveObject(GameObject*object);

	void Init(SDL_Renderer*renderer);
	void Update();
	void Render();
	void Dispose();
};
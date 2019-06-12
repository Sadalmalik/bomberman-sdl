#include "pch.h"

#include "functions.h"
#include "scene.h"

Scene::Scene() :
	_renderer(nullptr),
	_objects()
{}

Scene::~Scene()
{}

void Scene::AddObject(GameObject*object)
{
	_objects.push_back(object);
	object->Init(_renderer);
}

void Scene::RemoveObject(GameObject*object)
{
	auto it = std::find(_objects.begin(), _objects.end(), object);
	if (it != _objects.end())
		_objects.erase(it);
	object->Dispose();
}

void Scene::Init(SDL_Renderer*renderer)
{
	_renderer = renderer;
}

void Scene::Update()
{
	for (auto obj : _objects)
		if (obj->active)
			obj->Update();
}

bool CompareObjectsOrder(const GameObject*obj1, const GameObject*obj2)
{
	return
		(obj1->zIndex == obj2->zIndex) ?
		(obj1->position.y < obj2->position.y) :
		(obj1->zIndex < obj2->zIndex) ;
}

void Scene::Render()
{
	std::sort(_objects.begin(), _objects.end(), CompareObjectsOrder);

	for (auto obj : _objects)
		if (obj->active)
			obj->Render(_renderer);
}

void Scene::Dispose()
{
	printf("Scene::Dispose");

	for (auto obj : _objects)
		obj->Dispose();

	_objects.clear();
}
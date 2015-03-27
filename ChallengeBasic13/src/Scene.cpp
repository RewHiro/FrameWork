#include "Scene.h"
#include "ResourceFactory.h"

void Scene::Load(const SceneType type){
	this->type = type;
	ResourceFactory factory;
	resource = factory.Create(type);
}
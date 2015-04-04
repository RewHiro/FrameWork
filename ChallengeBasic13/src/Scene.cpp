#include "Scene.h"
#include "ResourceFactory.h"
#include "SceneManager.h"

void Scene::Load(const SceneType type){
	this->type = type;
	resource = SceneManager::GetInstance().GetResource();
}
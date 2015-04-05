#include "Scene.h"
#include "ResourceFactory.h"
#include "SceneManager.h"
#include "Object.h"
#include "ObjectTask.h"
#include "ObjectInfo.h"

Scene::~Scene(){
	Object::GetObjectTask().Clear();
	Object::GetObjectInfo().Clear();
}

void Scene::Load(const SceneType type){
	this->type = type;
	resource = SceneManager::GetInstance().GetResource();
}
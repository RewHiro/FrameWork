#include "Scene.h"
#include "ResourceFactory.h"
#include "SceneManager.h"
#include "Object.h"
#include "ObjectTask.h"
#include "ObjectInfo.h"

Scene::~Scene(){
	Object::GetObjectTask().Clear();
	Object::GetObjectInfo().Clear();
	while(!Object::GetDeleteList().empty()){
		Object::GetDeleteList().pop();
	}
}

void Scene::Load(const SceneType type){
	this->type = type;
	resource = SceneManager::GetInstance().GetResource();
}
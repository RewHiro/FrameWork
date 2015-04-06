#include "Scene.h"
#include "ResourceFactory.h"
#include "SceneManager.h"
#include "Object.h"

Scene::Scene():
type(SceneManager::GetInstance().GetType()),
resource(SceneManager::GetInstance().GetResource())
{
}

Scene::~Scene(){
}

//　現在のシーンの切り替え
//　リソースの切り替え
void Scene::Load(const SceneType type){
	this->type = type;
	resource = SceneManager::GetInstance().GetResource();
}
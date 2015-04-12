#include "Scene.h"
#include "SceneManager.h"

Scene::Scene():
type(SceneManager::GetInstance().GetType()),
resource(SceneManager::GetInstance().GetResource())
{
}

Scene::~Scene(){
}
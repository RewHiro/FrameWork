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

//�@���݂̃V�[���̐؂�ւ�
//�@���\�[�X�̐؂�ւ�
void Scene::Load(const SceneType type){
	this->type = type;
	resource = SceneManager::GetInstance().GetResource();
}
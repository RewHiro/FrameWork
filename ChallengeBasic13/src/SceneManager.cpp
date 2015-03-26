#include "SceneManager.h"
#include "Title.h"
#include <unordered_map>
#include <functional>

SceneManager::SceneManager() :
type(SceneType::TITLE),
scene(Create(type))
{
	scene->LoadScene(type);
}

SceneManager& SceneManager::GetInstance(){
	static SceneManager scene_manager;
	return scene_manager;
}

void SceneManager::Update(){
	auto now_type = scene->Update();
	scene->Draw();

	if (type == now_type)return;
	scene = Create(now_type);
	type = now_type;
	scene->LoadScene(type);
	
}

std::shared_ptr<Scene> SceneManager::Create(const SceneType type){
	static const std::unordered_map<SceneType,std::function<std::shared_ptr<Scene>()>> scene_list = {
		{
			SceneType::TITLE,
			[]{return std::make_shared<Title>(); }
		}
	};
	return (scene_list.find(type))->second();
}
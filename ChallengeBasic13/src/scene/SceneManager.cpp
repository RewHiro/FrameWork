#include "SceneManager.h"
#include "Title.h"
#include "Stage.h"
#include "resource/ResourceFactory.h"
#include "resource/ResourceTitle.h"
#include "object/ObjectTask.h"
#include "object/ObjectInfo.h"
#include <functional>


SceneManager::SceneManager() :
type(SceneType::TITLE),
resource(ResourceFactory::GetInstance().Create(type)),
scene(Create(type))
{
	Object::GetObjectInfo();
}

//　更新
void SceneManager::Update(){
	auto now_type = scene->Update();
	scene->Draw();

	if (type == now_type)return;
	type = now_type;
	Object::GetObjectTask().Clear();
	Object::GetObjectInfo().Clear();
	while (!Object::GetObjectTask().GetDeleteList().empty()){
		Object::GetObjectTask().GetDeleteList().pop();
	}
	resource = ResourceFactory::GetInstance().Create(now_type);
	scene = Create(now_type);
}

//　シーンの生成
std::unique_ptr<Scene> SceneManager::Create(const SceneType type){
	static const std::unordered_map<SceneType,std::function<std::unique_ptr<Scene>()>> scene_list = {
		{
			SceneType::TITLE,
			[]{return std::make_unique<Title>(); }
		},
		{
			SceneType::STAGE,
			[]{return std::make_unique<Stage>(); }
		}
	};
	return std::move((scene_list.find(type))->second());
}
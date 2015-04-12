#pragma once
#include "Scene.h"

//
//　シーン管理(シングルトーン)
//

class SceneManager : private Uncopyable
{
	SceneManager();

	SceneType type;
	std::shared_ptr<Resource>resource;
	std::unique_ptr<Scene> scene;
	
	//　シーンの生成
	std::unique_ptr<Scene> Create(const SceneType type);
public:
	//　インスタンスの取得
	static SceneManager& SceneManager::GetInstance(){
		static SceneManager scene_manager;
		return scene_manager;
	}

	//　リソースの取得
	const Resource& GetResource()const{
		return *resource.get();
	}

	//　シーンのタイプを取得
	SceneType GetType()const{
		return type;
	}

	//　更新
	void Update();
private:
};
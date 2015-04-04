#pragma once
#include "lib\appEnv.hpp"
#include "Scene.h"
#include <memory>

class SceneManager
{
	SceneType type;
	std::unique_ptr<Scene> scene;
	std::unique_ptr<Scene> Create(const SceneType type);

	SceneManager();
	std::shared_ptr<Resource>resource;
public:
	static SceneManager& GetInstance();
	void Update();

	const std::shared_ptr<Resource> GetResource()const{
		return resource;
	}
private:
	void Load();
};
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
public:
	static SceneManager& GetInstance();
	void Update();
private:
	void Load();
};
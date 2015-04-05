#pragma once
#include "lib\appEnv.hpp"
#include "Resource.h"

enum class SceneType{
	TITLE,
	STAGE,
	RESULT,
};

class Scene
{
	SceneType type;
protected:
	SceneType Type()const{ return type; }
	std::shared_ptr<Resource>resource;
public:
	Scene() = default;
	virtual ~Scene();

	virtual void Start(){ return; }
	virtual SceneType Update() = 0;
	virtual void Draw() = 0;
	void LoadScene(const SceneType type){ this->type = type; }

	//Å@égópã÷é~
	void Load(const SceneType type);
};


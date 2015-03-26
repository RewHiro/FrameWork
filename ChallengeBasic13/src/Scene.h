#pragma once
#include "lib\appEnv.hpp"

enum class SceneType{
	TITLE,
	GAME,
	RESULT,
};

class Scene
{
	SceneType type;
protected:
	SceneType Type()const{ return type; }
public:
	Scene() = default;
	virtual ~Scene() = default;

	virtual SceneType Update() = 0;
	virtual void Draw() = 0;
	void LoadScene(const SceneType type){ this->type = type; }
};


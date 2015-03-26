#pragma once
#include "Scene.h"
class Title :
	public Scene
{
public:
	Title();

	SceneType Update() final;
	void Draw() final;
};


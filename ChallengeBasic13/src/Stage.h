#pragma once
#include "Scene.h"

class Stage :
	public Scene
{
public:
	Stage();

	SceneType Update() final;

	void Draw() final;
};


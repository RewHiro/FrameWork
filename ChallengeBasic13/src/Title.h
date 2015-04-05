#pragma once
#include "Scene.h"
#include "ObjectTask.h"
class Title :
	public Scene
{
	int frame_count = 0;
public:
	Title();
	void Start();

	SceneType Update() final;
	void Draw() final;
};


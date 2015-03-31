#pragma once
#include "Scene.h"
#include "Object.h"
#include "ObjectInfo.h"
class Title :
	public Scene
{
	int frame_count = 0;
	std::vector<std::shared_ptr<Object>>objects;
	ObjectInfo object_info;
public:
	Title();
	void Start();

	SceneType Update() final;
	void Draw() final;
};


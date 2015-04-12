#pragma once
#include "Scene.h"

//
//　タイトルシーン
//

class Title :
	public Scene
{
	int frame_count = 0;
public:
	Title();

	SceneType Update() final;
	void Draw() final;
};


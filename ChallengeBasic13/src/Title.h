#pragma once
#include "Scene.h"

//
//�@�^�C�g���V�[��
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


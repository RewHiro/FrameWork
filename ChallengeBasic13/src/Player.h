#pragma once
#include "Object.h"
#include "lib\graph.hpp"
class Player :
	public Object
{
	 int frame_count = 0;
	 Color color = Color(1, 1, 1);
	 const std::vector<Texture>& textures;
	 std::weak_ptr<Object>background;
public:
	Player();
	void Awake();
	void Start();
	void Update();
	void Draw();
};


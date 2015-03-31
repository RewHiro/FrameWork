#pragma once
#include "Object.h"
#include "Resource.h"
#include "lib\graph.hpp"
class Player :
	public Object
{
	 int frame_count = 0;
	 std::weak_ptr<Resource>resource;
	 Color color = Color(1, 1, 1);
	 const std::vector<Texture>& textures;
	 std::weak_ptr<Object>background;
public:
	Player(std::weak_ptr<Resource>resource);
	void Start();
	void Update();
	void Draw();
};


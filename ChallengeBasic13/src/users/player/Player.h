#pragma once
#include "object/Object.h"
#include "lib\graph.hpp"

class Player :
	public Object
{
	 const std::vector<Texture>& textures;
	 std::weak_ptr<Object>background;
	 std::weak_ptr<Object>point;
public:
	Player();
	Player(const Transform2D& transform2D);
	void Start();
	void Update();
	void Draw();
};


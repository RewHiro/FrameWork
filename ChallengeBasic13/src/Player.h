#pragma once
#include "Object.h"
#include "lib\graph.hpp"
class Player :
	public Object
{
	 const std::vector<Texture>& textures;
	 std::weak_ptr<Object>background;
public:
	Player();
	Player(Transform2D& transform2D);
	void Awake();
	void Start();
	void Update();
	void Draw();
};


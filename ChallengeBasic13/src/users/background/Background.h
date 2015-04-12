#pragma once
#include "object/Object.h"
#include "lib\graph.hpp"
class Background :
	public Object
{
	const Texture& texture;
	Color color = Color(1, 1, 1);
public:
	Background();
	void Update();
	void Start();
	void Draw();
};


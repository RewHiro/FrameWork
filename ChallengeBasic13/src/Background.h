#pragma once
#include "Object.h"
#include "Resource.h"
#include "lib\graph.hpp"
class Background :
	public Object
{
	const Texture& texture;
	std::weak_ptr<Resource>resource;
	Color color = Color(1, 1, 1);
public:
	Background(std::weak_ptr<Resource>resource, const ObjectInfo& object_info);
	void Draw();
};


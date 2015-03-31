#pragma once
#include "Component.h"
#include "Transform2D.h"
class PlayerMover :
	public Component
{
	Transform2D& transform2D;
public:
	bool test = false;
	PlayerMover(Transform2D& transform2D);
	void Update();
};


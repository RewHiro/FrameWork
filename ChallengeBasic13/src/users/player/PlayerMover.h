#pragma once
#include "component/Component.h"
#include "component/Transform2D.h"
class PlayerMover :
	public Component
{
public:
	bool test = false;
	PlayerMover(Object& object);
	void Start();
	void Update();
};


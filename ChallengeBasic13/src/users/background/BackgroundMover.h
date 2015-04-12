#pragma once
#include "component/Component.h"
#include "component/Transform2D.h"

class BackgroundMover :
	public Component
{
public:
	bool test = false;
	BackgroundMover(Object& object);
	void Update();
};


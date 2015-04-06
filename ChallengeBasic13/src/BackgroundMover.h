#pragma once
#include "Component.h"
#include "Transform2D.h"

class BackgroundMover :
	public Component
{
public:
	bool test = false;
	BackgroundMover(Object& object);
	void Update();
};


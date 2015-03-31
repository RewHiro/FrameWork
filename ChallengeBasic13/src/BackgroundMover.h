#pragma once
#include "Component.h"
#include "Transform2D.h"

class BackgroundMover :
	public Component
{
	Transform2D& transform2D;
public:
	bool test = false;
	BackgroundMover(Transform2D& transform2D, ComponentTask& component_task);
	void Update();
};


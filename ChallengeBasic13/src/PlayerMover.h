#pragma once
#include "Component.h"
#include "Transform2D.h"
class PlayerMover :
	public Component
{
public:
	bool test = false;
	PlayerMover();
	void Start();
	void Update();
};


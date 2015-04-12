#pragma once
#include "component/Component.h"
class PlayerTest :
	public Component
{
public:
	bool test = true;
	PlayerTest(Object& object);
};


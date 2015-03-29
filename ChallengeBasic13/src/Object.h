#pragma once
#include "Uncopyable.h"
#include "lib\vector.hpp"
#include "Transform2D.h"
class Object :
	private Uncopyable
{
protected:
	Transform2D transform2D;
public:
	Object() = default;
	virtual ~Object() = default;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};


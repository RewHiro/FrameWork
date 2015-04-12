#pragma once
#include "component\Component.h"

class Point;
//class Line;
class Rect;
//class Circle;

class Shape : public Component
{

public:
	virtual bool Collision(const Point& point)const = 0;
	//virtual bool Collision(const Line& line) = 0;
	virtual bool Collision(const Rect& rect)const = 0;
	//virtual bool Collision(const Circle& circle) = 0;
	Shape(Object& object);
	virtual bool Hit(const Shape& shape)const = 0;
};


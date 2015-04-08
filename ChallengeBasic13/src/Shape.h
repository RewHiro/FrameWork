#pragma once
#include "Component.h"

class Point;
class Line;
class Rect;
class Circle;

class Shape : public Component
{

public:
	Shape(Object& object);
	bool Hit(Shape& shape);
	bool Collision(Point& point);
	bool Collision(Line& point);
	bool Collision(Rect& point);
	bool Collision(Circle& point);
};


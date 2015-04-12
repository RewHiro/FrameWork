#pragma once
#include "Shape.h"
class Point : public Shape
{
	bool Collision(const Point& point)const final;
	//bool Hit(std::weak_ptr<Line>point);
	bool Collision(const Rect& rect)const final;
	//bool Hit(std::weak_ptr<Circle>point);
public:
	Point(Object& object);
	bool Hit(const Shape& shape)const final;
};


#pragma once
#include "Shape.h"
class Rect : public Shape
{
	bool Collision(const Point& point)const final;
	//bool Hit(std::weak_ptr<Line>point);
	bool Collision(const Rect& rect)const final;
	//bool Hit(std::weak_ptr<Circle>point);
public:
	Rect(Object& object);
	virtual bool Hit(const Shape& shape)const final;
};


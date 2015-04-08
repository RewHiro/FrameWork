#pragma once
#include "Shape.h"
class Point : public Shape
{
public:
	Point(Object& object);
	bool Hit(std::weak_ptr<Point>point);
	bool Hit(std::weak_ptr<Line>point);
	bool Hit(std::weak_ptr<Rect>point);
	bool Hit(std::weak_ptr<Circle>point);
};


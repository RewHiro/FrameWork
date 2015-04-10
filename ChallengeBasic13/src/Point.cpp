#include "Point.h"
#include "Rect.h"

Point::Point(Object& object) :
Shape(object)
{
}

bool Point::Collision(const Point& point)const{
	if (object.transform2D.PosX() != point.object.transform2D.PosX())return false;
	if (object.transform2D.PosY() != point.object.transform2D.PosY())return false;
	return true;
}

bool Point::Collision(const Rect& rect)const{
	if (!(object.transform2D.PosX() > rect.object.transform2D.PosX() &&
		rect.object.transform2D.SizeX() + rect.object.transform2D.PosX() > object.transform2D.PosX()))return false;
	if (!(object.transform2D.PosY() > rect.object.transform2D.PosY() &&
		rect.object.transform2D.SizeY() + rect.object.transform2D.PosY() > object.transform2D.PosY()))return false;
	return true;
}

bool Point::Hit(const Shape& shape)const{
	return shape.Collision(*this);
}
#include "Rect.h"
#include "Point.h"

Rect::Rect(Object& object):
Shape(object)
{
}

bool Rect::Collision(const Point& point)const{
	if (object.transform2D.PosX() != point.object.transform2D.PosX())return false;
	if (object.transform2D.PosY() != point.object.transform2D.PosY())return false;
	return true;
}
bool Rect::Collision(const Rect& rect)const{
	if (!(rect.object.transform2D.PosX() < object.transform2D.PosX() &&
		object.transform2D.SizeX() + object.transform2D.PosX() < rect.object.transform2D.PosX()))return false;
	if (!(rect.object.transform2D.PosY() < object.transform2D.PosY() &&
		object.transform2D.SizeY() + object.transform2D.PosY() < rect.object.transform2D.PosX()))return false;
	return true;
}

bool Rect::Hit(const Shape& shape)const{
	return shape.Collision(*this);
}
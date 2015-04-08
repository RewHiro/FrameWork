#include "Rect.h"
#include "Point.h"

Rect::Rect(Object& object):
Shape(object)
{
}

bool Rect::Hit(std::weak_ptr<Point>point){
	if (object.transform2D.PosX() != point.lock()->object.transform2D.PosX())return false;
	if (object.transform2D.PosY() != point.lock()->object.transform2D.PosY())return false;
	return true;
}
bool Rect::Hit(std::weak_ptr<Line>point){
	return false;
}
bool Rect::Hit(std::weak_ptr<Rect>point){
	if (!(point.lock()->object.transform2D.PosX() < object.transform2D.PosX() &&
		object.transform2D.SizeX() + object.transform2D.PosX() < point.lock()->object.transform2D.PosX()))return false;
	if (!(point.lock()->object.transform2D.PosY() < object.transform2D.PosY() &&
		object.transform2D.SizeY() + object.transform2D.PosY() < point.lock()->object.transform2D.PosX()))return false;
	return true;
}
bool Rect::Hit(std::weak_ptr<Circle>point){
	return false;
}
#include "Point.h"
#include "Rect.h"

Point::Point(Object& object) :
Shape(object)
{
}

bool Point::Hit(std::weak_ptr<Point>point){
	if (object.transform2D.PosX() != point.lock()->object.transform2D.PosX())return false;
	if (object.transform2D.PosY() != point.lock()->object.transform2D.PosY())return false;
	return true;
}
bool Point::Hit(std::weak_ptr<Line>point){
	return false;
}
bool Point::Hit(std::weak_ptr<Rect>point){
	if (!(object.transform2D.PosX() < point.lock()->object.transform2D.PosX() &&
		point.lock()->object.transform2D.SizeX() + point.lock()->object.transform2D.PosX() < object.transform2D.PosX()))return false;
	if (!(object.transform2D.PosY() < point.lock()->object.transform2D.PosY() &&
		point.lock()->object.transform2D.SizeY() + point.lock()->object.transform2D.PosY() < object.transform2D.PosX()))return false;
	return true;
}
bool Point::Hit(std::weak_ptr<Circle>point){
	return false;
}
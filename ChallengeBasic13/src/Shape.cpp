#include "Shape.h"
#include "Point.h"
#include "Rect.h"

Shape::Shape(Object& object) :
Component(object)
{
}

bool Shape::Collision(Point& point){
	//@¡‚ÍƒGƒ‰[‰ñ”ğ‚Ì‚½‚ßˆø”point‚ğ“ü‚ê‚Ä‚¢‚é
	//point.Hit(point/*(object.shape)*/);
	return false;
}
bool Shape::Collision(Line& line){
	return false;
}
bool Shape::Collision(Rect& rect){
	return false;
}
bool Shape::Collision(Circle& circle){
	return false;
}

bool Shape::Hit(Shape& shape){

	return false;	//return Collision(shape.This());
}
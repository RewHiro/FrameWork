#include "Shape.h"
#include "Point.h"
#include "Rect.h"

Shape::Shape(Object& object) :
Component(object)
{
}

bool Shape::Collision(Point& point){
	//�@���̓G���[����̂��߈���point�����Ă���
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
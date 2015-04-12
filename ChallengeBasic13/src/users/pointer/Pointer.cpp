#include "Pointer.h"
#include "system/Application.h"
#include "component/collision/Point.h"

Pointer::Pointer():
Object(Transform2D(Application::mousePositon(),Vec2f(20,20)),std::make_shared<Point>(*this),1)
{
}

void Pointer::Start(){
}
void Pointer::Update(){
	transform2D.Position() = Application::mousePositon();
}
void Pointer::Draw(){
	drawFillCircle(transform2D.PosX(), transform2D.PosY(), transform2D.SizeX(), transform2D.SizeY(), 20, color);
}
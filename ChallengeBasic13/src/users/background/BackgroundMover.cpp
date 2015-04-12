#include "BackgroundMover.h"
#include "component/ComponentTask.h"
#include "system/Application.h"

BackgroundMover::BackgroundMover(Object& object):
Component(object)
{
}

void BackgroundMover::Update(){
	if(Application::isPressKey('A')){
		object.transform2D.PosX() += -10;
	}
}
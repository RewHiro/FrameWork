#include "BackgroundMover.h"
#include "ComponentTask.h"
#include "Application.h"

BackgroundMover::BackgroundMover(Object& object):
Component(object)
{
}

void BackgroundMover::Update(){
	if(Application::isPressKey('A')){
		object.transform2D.PosX() += -10;
	}
}
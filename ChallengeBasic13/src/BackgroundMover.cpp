#include "BackgroundMover.h"
#include "ComponentTask.h"
#include "Application.h"

BackgroundMover::BackgroundMover(Transform2D& transform2D, ComponentTask& component_task):
transform2D(transform2D),
Component(component_task)
{
}

void BackgroundMover::Update(){
	if(Application::isPressKey('A')){
		transform2D.PosX() += -10;
	}
}
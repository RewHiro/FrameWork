#include "BackgroundMover.h"
#include "ComponentTask.h"
#include "Application.h"

BackgroundMover::BackgroundMover()
{
}

void BackgroundMover::Update(){
	if(Application::isPressKey('A')){
		object.lock()->transform2D.PosX() += -10;
	}
}
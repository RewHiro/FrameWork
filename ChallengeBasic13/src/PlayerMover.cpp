#include "PlayerMover.h"
#include "Application.h"
#include "Object.h"
#include "ObjectInfo.h"
#include "BackgroundMover.h"
#include "PlayerTest.h"
#include <iostream>

PlayerMover::PlayerMover(Transform2D& transform2D, ComponentTask& component_task) :
transform2D(transform2D),
Component(component_task)
{

}

void PlayerMover::Start(){
	ObjectFind("background")->GetComponent<BackgroundMover>("BackgroundMover")->test = true;
	GetComponent<PlayerTest>("PlayerTest")->test = false;
}

void PlayerMover::Update(){
	std::cout << ObjectFind("background")->GetTransform2D().Position() << std::endl;

	if(Application::isPressKey('W')){
		transform2D.PosY() += 10;
	}
}
#include "PlayerMover.h"
#include "Application.h"
#include "Object.h"
#include "ObjectInfo.h"
#include "BackgroundMover.h"
#include "PlayerTest.h"
#include <iostream>

PlayerMover::PlayerMover()
{
}

void PlayerMover::Start(){
	ObjectFind("Background")->GetComponent<BackgroundMover>()->test = true;

	auto a = GetComponent<PlayerTest>();
	a->test = false;
	//GetComponent<PlayerTest>()->test = false;
}

void PlayerMover::Update(){
	std::cout << ObjectFind("Background")->transform2D.Position() << std::endl;

	if(Application::isPressKey('W')){
		object.lock()->transform2D.PosY() += 10;
	}
}
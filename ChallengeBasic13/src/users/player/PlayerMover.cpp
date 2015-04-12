#include "PlayerMover.h"
#include "system/Application.h"
#include "object/Object.h"
#include "object/ObjectInfo.h"
#include "users\background\BackgroundMover.h"
#include "PlayerTest.h"
#include "Player.h"
#include <iostream>

PlayerMover::PlayerMover(Object& object):
Component(object)
{

}

void PlayerMover::Start(){

	ObjectFind("Background")->GetComponent<BackgroundMover>()->test = true;
	auto a = GetComponent<PlayerTest>();
	a->test = false;
	GetComponent<PlayerTest>()->test = false;
}

void PlayerMover::Update(){
	//std::cout << ObjectFind("Background")->transform2D.Position() << std::endl;
	if(Application::isPressKey('W')){
		object.transform2D.PosY() += 10;
	}
}
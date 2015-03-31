#include "Player.h"
#include "ObjectInfo.h"
#include "PlayerMover.h"
#include "PlayerTest.h"
#include <iostream>

Player::Player(std::weak_ptr<Resource>resource) :
resource(resource),
textures(resource.lock()->AnimationFind("miku")),
Object(Transform2D(Vec2f::Zero(),Vec2f(128,128)),1)
{
	ComponentAdd("PlayerMover", std::make_shared<PlayerMover>(transform2D,component_task));
	ComponentAdd("PlayerTest", std::make_shared<PlayerTest>(component_task));
}

void Player::Start(){
	ComponetStart();
	background = ObjectFind("background");
	GetComponent<PlayerMover>("PlayerMover")->test = true;
}

void Player::Update(){
	ComponetnUpdate();
	//std::cout << background.lock()->GetTransform2D().PosX() << std::endl;
	frame_count++;
}

void Player::Draw(){
	drawTextureBox(transform2D.PosX(), transform2D.PosY(), transform2D.SizeX(), transform2D.SizeY(),
		0, 0, 310, 270, textures.at(frame_count / 30 % 6), color);
}
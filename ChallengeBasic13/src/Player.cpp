#include "Player.h"
#include "ObjectInfo.h"
#include "PlayerMover.h"
#include "PlayerTest.h"
#include "Application.h"
#include <iostream>

Player::Player() :
textures(GetResource()->AnimationFind("miku")),
Object(Transform2D(Vec2f::Zero(),Vec2f(128,128)),1)
{

}

Player::Player(Transform2D& transform2D) :
textures(GetResource()->AnimationFind("miku")),
Object(transform2D, 1)
{

}

void Player::Awake(){
	ComponentAdd(std::make_shared<PlayerMover>());
	ComponentAdd(std::make_shared<PlayerTest>());
}

void Player::Start(){
	ComponetStart();
	background = ObjectFind("Background");
	GetComponent<PlayerMover>()->test = true;
}

void Player::Update(){
	ComponetnUpdate();
	//std::cout << background.lock()->GetTransform2D().PosX() << std::endl;
	frame_count++;
	if(Application::isPushKey('E')){
		Destory(shared_from_this());
	}
}

void Player::Draw(){
	drawTextureBox(transform2D.PosX(), transform2D.PosY(), transform2D.SizeX(), transform2D.SizeY(),
		0, 0, 310, 270, textures.at(frame_count / 30 % 6), color);
}
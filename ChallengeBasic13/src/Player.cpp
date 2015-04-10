#include "Player.h"
#include "ObjectInfo.h"
#include "PlayerMover.h"
#include "PlayerTest.h"
#include "Application.h"
#include "Resource.h"
#include "Rect.h"
#include <iostream>

Player::Player() :
textures(GetResource()->AnimationFind("miku")),
Object(Transform2D(Vec2f::Zero(),Vec2f(128,128)),std::make_shared<Rect>(*this),1)
{
	ComponentAdd(std::make_shared<PlayerMover>(*this));
	ComponentAdd(std::make_shared<PlayerTest>(*this));
}

Player::Player(const Transform2D& transform2D) :
textures(GetResource()->AnimationFind("miku")),
Object(transform2D, 1)
{
	ComponentAdd(std::make_shared<PlayerMover>(*this));
	ComponentAdd(std::make_shared<PlayerTest>(*this));
}

void Player::Start(){
	ComponetStart();
	background = ObjectFind("Background");
	GetComponent<PlayerMover>()->test = true;
	point = ObjectFind("Pointer");
}

void Player::Update(){
	ComponetnUpdate();
	//std::cout << background.lock()->GetTransform2D().PosX() << std::endl;
	frame_count++;
	if(Application::isPushKey('E')){
		Destory(shared_from_this());
	}

	color = Hit(point) ? Color(1.0f, .0f, .0f) : Color(1.0f, 1.0f, 1.0f);
}

void Player::Draw(){
	drawTextureBox(transform2D.PosX(), transform2D.PosY(), transform2D.SizeX(), transform2D.SizeY(),
		0, 0, 310, 270, textures.at(frame_count / 30 % 6), color);

	drawBox(transform2D.PosX(), transform2D.PosY(), transform2D.SizeX(), transform2D.SizeY(),5, color);
}
#include "Player.h"
#include "ObjectInfo.h"
#include <iostream>

Player::Player(std::weak_ptr<Resource>resource) :
resource(resource),
textures(resource.lock()->AnimationFind("miku")),
Object(Transform2D(Vec2f::Zero(),Vec2f(128,128)))
{

}

void Player::Start(){
	background = ObjectFind("background");
}

void Player::Update(){

	std::cout << background.lock()->GetTransform2D().Position() << std::endl;
	frame_count++;
}

void Player::Draw(){
	drawTextureBox(transform2D.PosX(), transform2D.PosY(), transform2D.SizeX(), transform2D.SizeY(),
		0, 0, 310, 270, textures.at(frame_count / 30 % 6), color);
}
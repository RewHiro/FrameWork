#include "Background.h"
#include "system/Application.h"
#include "BackgroundMover.h"
#include "resource/Resource.h"
Background::Background() :
texture(GetResource().TextureFind("bg")),
Object(Transform2D(-Application::viewSize().array()*.5f, Application::viewSize()))
{
	ComponentAdd(std::make_shared<BackgroundMover>(*this));
}

void Background::Start(){
	ComponetStart();
}

void Background::Update(){
	ComponetnUpdate();
}

void Background::Draw(){
	drawTextureBox(transform2D.PosX(), transform2D.PosY(), transform2D.SizeX(), transform2D.SizeY(),
		0, 0, texture.width(), texture.height(), texture, color);
}
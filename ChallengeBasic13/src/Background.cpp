#include "Background.h"
#include "Application.h"
#include "BackgroundMover.h"
Background::Background(std::weak_ptr<Resource>resource) :
resource(resource),
texture(resource.lock()->TextureFind("bg")),
Object(Transform2D(-Application::viewSize().array()*.5f, Application::viewSize()))
{
	ComponentAdd("BackgroundMover", std::make_shared<BackgroundMover>(transform2D, component_task));
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
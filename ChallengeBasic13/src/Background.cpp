#include "Background.h"
#include "Application.h"
Background::Background(std::weak_ptr<Resource>resource, const ObjectInfo& object_info) :
resource(resource),
texture(resource.lock()->TextureFind("bg")),
Object(Transform2D(-Application::viewSize().array()*.5f, Application::viewSize()),object_info)
{
}

void Background::Draw(){
	drawTextureBox(transform2D.PosX(), transform2D.PosY(), transform2D.SizeX(), transform2D.SizeY(),
		0, 0, texture.width(), texture.height(), texture, color);
}
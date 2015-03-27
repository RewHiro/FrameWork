#include "Title.h"
#include "Application.h"

Title::Title()
{
}

void Title::Start(){
	auto bgm = resource->BGMFind("title");
	bgm.looping(true);
	bgm.play();
}

SceneType Title::Update(){

	if(Application::isPushButton(Mouse::LEFT)){
		LoadScene(SceneType::STAGE);
		resource->BGMFind("title").stop();
	}
	frame_count++;
	if(Application::isPushButton(Mouse::RIGHT)){
		resource->SEFind("hit").play();
	}
	return Type();
}

void Title::Draw(){
	{
		auto window_size = Application::viewSize();
		auto texture = resource->TextureFind("bg");
		drawTextureBox(-window_size.x()*.5f, -window_size.y()*.5f, window_size.x(), window_size.y(),
			0, 0, texture.width(), texture.height(), texture, Color(1, 1, 1));
	}

	{
		auto texture = resource->AnimationFind("miku", frame_count / 30 % 6);
		drawTextureBox(0, 0, 128, 128,
			0, 0, 310, 270, texture, Color(1, 1, 1));
	}

	{
	auto pos = Application::mousePositon();
	drawFillCircle(pos.x(), pos.y(), 10, 10, 20, Color(1, 1, 1));
	}
}
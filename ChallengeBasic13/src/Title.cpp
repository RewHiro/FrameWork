#include "Title.h"
#include "Application.h"
#include "Player.h"
#include "Background.h"

Title::Title()
{

}

void Title::Start(){
	auto bgm = resource->BGMFind("title");
	bgm.looping(true);
	bgm.play();


	objects.emplace_back(std::make_shared<Background>(resource, object_info));
	objects.emplace_back(std::make_shared<Player>(resource, object_info));

	object_info.Add("background", objects.at(0));
	object_info.Add("player", objects.at(1));
}

SceneType Title::Update(){

	if(Application::isPushButton(Mouse::LEFT)){
		LoadScene(SceneType::STAGE);
		resource->BGMFind("title").stop();
	}
	for(auto& object : objects){
		object->Update();
	}
	frame_count++;
	if(Application::isPushButton(Mouse::RIGHT)){
		resource->SEFind("hit").play();
	}
	return Type();
}

void Title::Draw(){

	for (auto& object : objects){
		object->Draw();
	}

	{
	auto pos = Application::mousePositon();
	drawFillCircle(pos.x(), pos.y(), 10, 10, 20, Color(1, 1, 1));
	}
}
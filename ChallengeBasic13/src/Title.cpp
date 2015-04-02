#include "Title.h"
#include "Application.h"
#include "Player.h"
#include "Background.h"

Title::Title()
{

}

//　リソース取得の場合
void Title::Start(){
	auto bgm = resource->BGMFind("title");
	bgm.looping(true);
	bgm.play();

	object_task.Add("Player",std::make_shared<Player>(resource));
	object_task.Add("Background",std::make_shared<Background>(resource));

	object_task.Start();

}

SceneType Title::Update(){

	if(Application::isPushButton(Mouse::LEFT)){
		LoadScene(SceneType::STAGE);
		resource->BGMFind("title").stop();
	}
	object_task.Update();
	frame_count++;
	if(Application::isPushButton(Mouse::RIGHT)){
		resource->SEFind("hit").play();
	}
	return Type();
}

void Title::Draw(){

	object_task.Draw();

	{
	auto pos = Application::mousePositon();
	drawFillCircle(pos.x(), pos.y(), 10, 10, 20, Color(1, 1, 1));
	}
}
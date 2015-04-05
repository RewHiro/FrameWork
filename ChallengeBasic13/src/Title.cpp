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
	Object::ObjectAdd("Player", std::make_shared<Player>());
	Object::ObjectAdd("Background", std::make_shared<Background>());

	Object::GetObjectTask().Awake();
	Object::GetObjectTask().Start();

}

SceneType Title::Update(){

	if(Application::isPushButton(Mouse::LEFT)){
		LoadScene(SceneType::STAGE);
		resource->BGMFind("title").stop();
	}
	Object::GetObjectTask().Update();
	frame_count++;
	if(Application::isPushButton(Mouse::RIGHT)){
		resource->SEFind("hit").play();
	}
	Object::GetObjectTask().Erase();
	return Type();
}

void Title::Draw(){

	Object::GetObjectTask().Draw();

	{
	auto pos = Application::mousePositon();
	drawFillCircle(pos.x(), pos.y(), 10, 10, 20, Color(1, 1, 1));
	}
}
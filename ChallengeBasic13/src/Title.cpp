#include "Title.h"
#include "Application.h"
#include "Player.h"
#include "Background.h"
#include "ObjectTask.h"
#include "Resource.h"

Title::Title()
{
	auto bgm = resource->BGMFind("title");
	bgm.looping(true);
	bgm.play();
	Object::ObjectAdd("Player", std::make_shared<Player>());
	Object::ObjectAdd("Background", std::make_shared<Background>());
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
	Object::GetObjectTask().Update();
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
#include "Title.h"
#include "system/Application.h"
#include "users/player/Player.h"
#include "users/background/Background.h"
#include "users/pointer/Pointer.h"
#include "object/ObjectTask.h"
#include "resource/Resource.h"

Title::Title()
{
	auto& bgm = resource.BGMFind("title");
	bgm.looping(true);
	bgm.play();
	Object::ObjectAdd("Player", std::make_shared<Player>());
	Object::ObjectAdd("Background", std::make_shared<Background>());
	Object::ObjectAdd("Pointer", std::make_shared<Pointer>());
}

SceneType Title::Update(){
	if(Application::isPushButton(Mouse::LEFT)){
		LoadScene(SceneType::STAGE);
		resource.BGMFind("title").stop();
	}
	frame_count++;
	if(Application::isPushButton(Mouse::RIGHT)){
		resource.SEFind("hit").play();
	}
	if(Application::isPushKey('O')){
		Object::ObjectAdd("Player", std::make_shared<Player>());
	}
	Object::GetObjectTask().Update();
	Object::GetObjectTask().Erase();
	return Type();
}

void Title::Draw(){

	Object::GetObjectTask().Draw();
}
#include "Stage.h"
#include "system/Application.h"

Stage::Stage()
{
}

SceneType Stage::Update(){
	if (Application::isPushButton(Mouse::LEFT)){
		LoadScene(SceneType::TITLE);
	}
	return Type();
}

void Stage::Draw(){
	drawFillBox(0, 0, 50, 50, Color(1, 1, 1));
}
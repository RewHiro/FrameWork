#include "Title.h"
#include "Application.h"

Title::Title()
{
}

SceneType Title::Update(){
	if(Application::isPushButton(Mouse::LEFT)){
		LoadScene(SceneType::STAGE);
	}
	return Type();
}

void Title::Draw(){
	auto pos = Application::mousePositon();
	drawFillCircle(pos.x(), pos.y(), 10, 10, 20, Color(1, 1, 1));
}
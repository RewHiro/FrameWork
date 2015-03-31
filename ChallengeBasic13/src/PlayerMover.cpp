#include "PlayerMover.h"
#include "Application.h"

PlayerMover::PlayerMover(Transform2D& transform2D):
transform2D(transform2D)
{
}

void PlayerMover::Update(){
	if(Application::isPressKey('W')){
		transform2D.PosY() += 10;
	}
}
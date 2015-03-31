#include "ObjectTask.h"


ObjectTask::ObjectTask()
{
}

void ObjectTask::Start(){
	for (auto& object : objects){
		object->Start();
	}
}

void ObjectTask::Update(){
	for(auto& object : objects){
		object->Update();
	}
}

void ObjectTask::Draw(){
	for (auto& object : objects){
		object->Draw();
	}
}
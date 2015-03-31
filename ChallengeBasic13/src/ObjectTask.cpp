#include "ObjectTask.h"


ObjectTask::ObjectTask()
{
}

ObjectTask::~ObjectTask()
{
	Object::GetObjectInfo().Clear();
}

void ObjectTask::Start(){
	for (auto& object : objects){
		object->Start();
	}
	std::stable_sort(objects.begin(), objects.end(), [](std::weak_ptr<Object> a, std::weak_ptr<Object> b){return a.lock()->SortingNum() > b.lock()->SortingNum(); });
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
#include "ObjectTask.h"


ObjectTask::ObjectTask()
{
}

ObjectTask::~ObjectTask()
{
}

void ObjectTask::Add(const std::string& name, std::shared_ptr<Object>object){
	objects.emplace_back(object);
	std::stable_sort(objects.begin(), objects.end(), [](std::weak_ptr<Object> a, std::weak_ptr<Object> b){
		return a.lock()->SortingNum() > b.lock()->SortingNum();
	});
}

void ObjectTask::Awake(){
	for (auto& object : objects){
		object->Awake();
	}
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

void ObjectTask::Clear(){
	objects.clear();
}
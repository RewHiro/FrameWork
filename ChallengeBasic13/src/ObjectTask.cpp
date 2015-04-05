#include "ObjectTask.h"
#include <algorithm>

ObjectTask::ObjectTask()
{
}

ObjectTask::~ObjectTask()
{
}

void ObjectTask::Add(const std::string& name, std::shared_ptr<Object>object){
	objects.emplace_front(object);
	objects.sort([](std::weak_ptr<Object> a, std::weak_ptr<Object> b){return a.lock()->SortingNum() > b.lock()->SortingNum(); });
}

void ObjectTask::Awake(){
	for (auto& object : objects){
		if (object == nullptr)continue;
		object->Awake();
	}
}

void ObjectTask::Start(){
	for (auto& object : objects){
		if (object == nullptr)continue;
		object->Start();
	}

}

void ObjectTask::Update(){
	for(auto& object : objects){
		if (!object)continue;
		object->Update();
	}
}

void ObjectTask::Draw(){
	for (auto& object : objects){
		if (object == nullptr)continue;
		object->Draw();
	}
}

void ObjectTask::Clear(){
	objects.clear();
}

void ObjectTask::Erase(){
	while(!Object::GetDeleteList().empty()){
		auto object = Object::GetDeleteList().top();
		if(object == nullptr){
			Object::GetDeleteList().pop();
			continue;
		}
		objects.remove(object);
		Object::GetObjectInfo().Erase(object);
		Object::GetDeleteList().pop();
	}
}
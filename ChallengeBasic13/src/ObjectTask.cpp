#include "ObjectTask.h"
#include "ObjectInfo.h"
#include <algorithm>

ObjectTask::ObjectTask()
{
}

//　追加
void ObjectTask::Add(const std::string& name, std::shared_ptr<Object>object){
	objects.emplace_front(object);
	objects.sort([](std::weak_ptr<Object> a, std::weak_ptr<Object> b){return a.lock()->SortingNum() > b.lock()->SortingNum(); });
}

//　Start関数が実行する前に実行される
void ObjectTask::Awake(){
	for (auto& object : objects){
		object->Awake();
	}
}

//　Update関数が実行する前に実行される
void ObjectTask::Start(){
	for (auto& object : objects){
		object->Start();
	}

}

//　更新
void ObjectTask::Update(){
	for(auto& object : objects){
		object->Update();
	}
}

//　描画
void ObjectTask::Draw(){
	for (auto& object : objects){
		object->Draw();
	}
}

//　オブジェクト一覧の全削除
void ObjectTask::Clear(){
	objects.clear();
}

//　削除
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
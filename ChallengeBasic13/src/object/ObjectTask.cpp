#include "ObjectTask.h"
#include "ObjectInfo.h"
#include <algorithm>

ObjectTask::ObjectTask()
{
}

//　追加
void ObjectTask::Add(const std::string& name, const std::shared_ptr<Object>& object){
	objects.emplace_front(object);
	objects.sort([](std::weak_ptr<Object> a, std::weak_ptr<Object> b){return a.lock()->SortingNum() > b.lock()->SortingNum(); });
}

//　更新
void ObjectTask::Update()const{
	for(auto& object : objects){
		switch (object->GetUpdateState())
		{
		case UpdateState::UPDATE:
			object->Update();
			break;
		case UpdateState::START:
			object->Start();
			object->GetUpdateState() = UpdateState::UPDATE;
			break;
		}
	}
}

//　描画
void ObjectTask::Draw()const{
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
	while(!GetDeleteList().empty()){
		auto& object = GetDeleteList().top();
		if(object == nullptr){
			GetDeleteList().pop();
			continue;
		}
		objects.remove(object);
		Object::GetObjectInfo().Erase(object);
		GetDeleteList().pop();
	}
}
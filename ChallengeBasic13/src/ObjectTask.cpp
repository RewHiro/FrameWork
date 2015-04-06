#include "ObjectTask.h"
#include "ObjectInfo.h"
#include <algorithm>

ObjectTask::ObjectTask()
{
}

//�@�ǉ�
void ObjectTask::Add(const std::string& name, std::shared_ptr<Object>object){
	objects.emplace_front(object);
	objects.sort([](std::weak_ptr<Object> a, std::weak_ptr<Object> b){return a.lock()->SortingNum() > b.lock()->SortingNum(); });
}

//�@Start�֐������s����O�Ɏ��s�����
void ObjectTask::Awake(){
	for (auto& object : objects){
		object->Awake();
	}
}

//�@Update�֐������s����O�Ɏ��s�����
void ObjectTask::Start(){
	for (auto& object : objects){
		object->Start();
	}

}

//�@�X�V
void ObjectTask::Update(){
	for(auto& object : objects){
		object->Update();
	}
}

//�@�`��
void ObjectTask::Draw(){
	for (auto& object : objects){
		object->Draw();
	}
}

//�@�I�u�W�F�N�g�ꗗ�̑S�폜
void ObjectTask::Clear(){
	objects.clear();
}

//�@�폜
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
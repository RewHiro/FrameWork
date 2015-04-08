#include "Object.h"
#include "ObjectInfo.h"
#include "ObjectTask.h"
#include "Component.h"
#include "SceneManager.h"
#include "Shape.h"

//�@�R���|�[�l���g�ǉ�
void Object::ComponentAdd(const std::shared_ptr<Component>& component){
	component_task.Add(component);
	component_info.Add(component);
}

//�@�R���|�[�l���g�X�V
void Object::ComponetStart(){
	component_task.Start();
}
void Object::ComponetnUpdate(){
	component_task.Update();
}

//�@���\�[�X�擾
const std::shared_ptr<Resource> Object::GetResource(){
	return SceneManager::GetInstance().GetResource();
}

bool Object::Hit(std::weak_ptr<Object>object){
	return false;
	//return shape->Collision(object.lock()->shape);
}

ObjectInfo& Object::GetObjectInfo(){
	static ObjectInfo object_info;
	return object_info;
}
ObjectTask& Object::GetObjectTask(){
	static ObjectTask object_task;
	return object_task;
}

//�@�I�u�W�F�N�g�擾
const std::shared_ptr<Object> Object::ObjectFind(const std::string& name)const{
	return GetObjectInfo().Find(name);
}

//�@�I�u�W�F�N�g�擾(����)
const std::pair<OBJECT_MAP_ITR, OBJECT_MAP_ITR> Object::ObjectFinds(const std::string& name){
	return GetObjectInfo().Finds(name);
}

//�@�I�u�W�F�N�g�ǉ�
void Object::ObjectAdd(const std::string& name, std::shared_ptr<Object>object){
	object->name = name;
	GetObjectInfo().Add(name, object);
	GetObjectTask().Add(name, object);
}

//�@�I�u�W�F�N�g�j��
void Object::Destory(const std::shared_ptr<Object>& object){
	is_delete = !is_delete;
	GetObjectTask().GetDeleteList().emplace(object);
}


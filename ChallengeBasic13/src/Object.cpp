#include "Object.h"
#include "ObjectInfo.h"
#include "ObjectTask.h"
#include "Component.h"
#include "SceneManager.h"


const std::shared_ptr<Object> Object::ObjectFind(const std::string& name)const{
	return GetObjectInfo().Find(name);
}

void Object::ObjectAdd(const std::string& name, std::shared_ptr<Object>object){
	object->name = name;
	GetObjectInfo().Add(name, object);
	GetObjectTask().Add(name, object);
}

ObjectInfo& Object::GetObjectInfo(){
	static ObjectInfo object_info;
	return object_info;
}

ObjectTask& Object::GetObjectTask(){
	static ObjectTask object_task;
	return object_task;
}

void Object::ComponentAdd(std::shared_ptr<Component>component){
	component_task.Add(component);
	component_info.Add(component);
	component->SetObject(shared_from_this());
}

const std::shared_ptr<Resource> Object::GetResource(){
	return SceneManager::GetInstance().GetResource();
}

void Object::Destory(std::shared_ptr<Object>object){
	is_delete = !is_delete;
	GetDeleteList().emplace(object);
}

std::stack<std::shared_ptr<Object>>& Object::GetDeleteList(){
	static std::stack<std::shared_ptr<Object>>delete_list;
	return delete_list;
}
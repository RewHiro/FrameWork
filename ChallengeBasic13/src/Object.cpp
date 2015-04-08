#include "Object.h"
#include "ObjectInfo.h"
#include "ObjectTask.h"
#include "Component.h"
#include "SceneManager.h"
#include "Shape.h"

//　コンポーネント追加
void Object::ComponentAdd(const std::shared_ptr<Component>& component){
	component_task.Add(component);
	component_info.Add(component);
}

//　コンポーネント更新
void Object::ComponetStart(){
	component_task.Start();
}
void Object::ComponetnUpdate(){
	component_task.Update();
}

//　リソース取得
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

//　オブジェクト取得
const std::shared_ptr<Object> Object::ObjectFind(const std::string& name)const{
	return GetObjectInfo().Find(name);
}

//　オブジェクト取得(複数)
const std::pair<OBJECT_MAP_ITR, OBJECT_MAP_ITR> Object::ObjectFinds(const std::string& name){
	return GetObjectInfo().Finds(name);
}

//　オブジェクト追加
void Object::ObjectAdd(const std::string& name, std::shared_ptr<Object>object){
	object->name = name;
	GetObjectInfo().Add(name, object);
	GetObjectTask().Add(name, object);
}

//　オブジェクト破壊
void Object::Destory(const std::shared_ptr<Object>& object){
	is_delete = !is_delete;
	GetObjectTask().GetDeleteList().emplace(object);
}


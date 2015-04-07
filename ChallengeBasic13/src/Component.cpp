#include "Component.h"
#include "ObjectInfo.h"

Component::Component(Object& object):
object(object)
{
}

//　オブジェクトの追加
void Component::ObjectAdd(const std::string& name, std::shared_ptr<Object>object){
	Object::ObjectAdd(name, object);
}


//　オブジェクト取得
const std::shared_ptr<Object> Component::ObjectFind(const std::string& name){
	return Object::GetObjectInfo().Find(name);
}

//　オブジェクト取得(複数)
const std::pair<OBJECT_MAP_ITR, OBJECT_MAP_ITR>& Component::ObjectFinds(const std::string& name){
	return Object::GetObjectInfo().Finds(name);
}
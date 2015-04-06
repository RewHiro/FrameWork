#include "Component.h"
#include "ObjectInfo.h"
#include "Object.h"
#include "ObjectTask.h"

Component::Component(Object& object):
object(object)
{
}

void Component::ObjectAdd(const std::string& name, std::shared_ptr<Object>object){
	Object::ObjectAdd(name, object);
}

const std::shared_ptr<Object> Component::ObjectFind(const std::string& name){
	return Object::GetObjectInfo().Find(name);
}

const std::pair<OBJECT_MAP_ITR, OBJECT_MAP_ITR>& Component::ObjectFinds(const std::string& name){
	return Object::GetObjectInfo().Finds(name);
}
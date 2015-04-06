#include "Component.h"
#include "ObjectInfo.h"
#include "Object.h"
#include "ObjectTask.h"

Component::Component()
{
}

void Component::ObjectAdd(const std::string& name, std::shared_ptr<Object>object){
	Object::ObjectAdd(name, object);
	object->Awake();
	object->Start();
}

const std::shared_ptr<Object> Component::ObjectFind(const std::string& name){
	return Object::GetObjectInfo().Find(name);
}

const std::pair<Component::OBJECT_MAP_ITR, Component::OBJECT_MAP_ITR>& Component::ObjectFinds(const std::string& name){
	return Object::GetObjectInfo().Finds(name);
}
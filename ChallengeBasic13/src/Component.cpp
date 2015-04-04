#include "Component.h"
#include "ObjectInfo.h"

Component::Component()
{
}

const std::shared_ptr<Object> Component::ObjectFind(const std::string& name){
	return Object::GetObjectInfo().Find(name);
}
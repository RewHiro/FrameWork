#include "Component.h"
#include "Object.h"
#include "ObjectInfo.h"

Component::Component(ComponentTask& component_task):
component_task(component_task)
{
}

const std::shared_ptr<Object> Component::ObjectFind(const std::string& name){
	return Object::GetObjectInfo().Find(name);
}
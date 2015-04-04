#include "Object.h"
#include  "ObjectInfo.h"
#include "Component.h"

const std::shared_ptr<Object> Object::ObjectFind(const std::string& name)const{
	return GetObjectInfo().Find(name);
}

ObjectInfo& Object::GetObjectInfo(){
	static ObjectInfo object_info;
	return object_info;
}

void Object::ComponentAdd(std::shared_ptr<Component>component){
	component_task.Add(component);
	component_info.Add(component);
	component->SetObject(shared_from_this());
}

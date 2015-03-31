#include "Object.h"
#include  "ObjectInfo.h"

const std::shared_ptr<Object> Object::ObjectFind(const std::string& name)const{
	return GetObjectInfo().Find(name);
}

ObjectInfo& Object::GetObjectInfo(){
	static ObjectInfo object_info;
	return object_info;
}
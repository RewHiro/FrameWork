#include "Object.h"
#include  "ObjectInfo.h"

std::shared_ptr<Object> Object::ObjectFind(const std::string& name)const{
	return object_info.Find(name);
}
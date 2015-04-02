#pragma once
#include "Uncopyable.h"
#include "ComponentTask.h"
#include  <memory>
#include <string>
#include <typeinfo>

class Object;
class Component;

class BaseObject :
	private Uncopyable
{
	
public:
	BaseObject();

	template <class Type>
	const std::shared_ptr<Type>GetComponent(const std::string& name)const{
		return std::dynamic_pointer_cast<Type>(component_task.Find(name));
	}

	template <class Type>
	const std::shared_ptr<Type>GetObjectType(const std::string& name)const{
		return std::dynamic_pointer_cast<Type>(ObjectFind(name));
	}

	virtual std::string Name()const{
		const type_info& id = typeid(*this);
		std::string name = id.name();
		return name.substr(6);
	}
};


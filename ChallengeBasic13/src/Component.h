#pragma once
#include<string>
#include <memory>
class Object;
class ComponentTask;
class Component
{
	ComponentTask& component_task;
protected:
	bool is_active = true;
	const std::shared_ptr<Object> ObjectFind(const std::string& name);

	template <class Type>
	std::shared_ptr<Type>GetComponent(const std::string& name)const{
		return std::dynamic_pointer_cast<Type>(component_task.Find(name));
	}

	template <class Type>
	std::shared_ptr<Type>GetObjectType(const std::string& name)const{
		return std::dynamic_pointer_cast<Type>(ObjectFind(name));
	}
public:
	Component() = default;
	Component(ComponentTask& component_task);
	virtual ~Component() = default;

	virtual void Update(){}
	virtual void Start(){}
};


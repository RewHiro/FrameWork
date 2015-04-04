#pragma once
#include "Transform2D.h"
#include "Object.h"
#include "Uncopyable.h"
#include<string>
#include <memory>
class Component : private Uncopyable
{
protected:
	std::weak_ptr<Object>object;
	bool is_active = true;
	const std::shared_ptr<Object> ObjectFind(const std::string& name);

	template <class Type>
	const std::shared_ptr<Type>GetComponent()const{
		std::string name = typeid(Type).name();
		return std::dynamic_pointer_cast<Type>(object.lock()->GetComponentInfo().Find(name.substr(6)));
	}

	template <class Type>
	const std::shared_ptr<Type>GetObjectType()const{
		std::string name = typeid(Type).name();
		return std::dynamic_pointer_cast<Type>(ObjectFind(name.substr(6)));
	}

public:
	Component();
	virtual ~Component() = default;

	virtual void Update(){}
	virtual void Start(){}

	void SetObject(std::shared_ptr<Object>object){
		this->object = object;
	}

	virtual std::string Name()const{
		const std::type_info& id = typeid(*this);
		std::string name = id.name();
		return name.substr(6);
	}
};


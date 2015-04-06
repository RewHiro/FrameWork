#pragma once
#include "Object.h"
#include "Uncopyable.h"
#include<string>
#include <memory>

//
//　コンポーネント(抽象クラス)
//

class Component : private Uncopyable
{
	UpdateState update_state = UpdateState::START;
protected:
	Object& object;
	bool is_active = true;
	const std::shared_ptr<Object> ObjectFind(const std::string& name);
	const std::pair<OBJECT_MAP_ITR, OBJECT_MAP_ITR>& ObjectFinds(const std::string& name);

	template <class Type>
	const std::shared_ptr<Type>GetComponent()const{
		std::string name = typeid(Type).name();
		return std::dynamic_pointer_cast<Type>(object.GetComponentInfo().Find(name.substr(6)));
	}

	template <class Type>
	const std::shared_ptr<Type>GetObjectType()const{
		std::string name = typeid(Type).name();
		return std::dynamic_pointer_cast<Type>(ObjectFind(name.substr(6)));
	}

	void ObjectAdd(const std::string& name, std::shared_ptr<Object>object);

public:
	Component(Object& object);
	virtual ~Component() = default;

	virtual void Update(){}
	virtual void Start(){}

	virtual std::string Name()const{
		const std::type_info& id = typeid(*this);
		std::string name = id.name();
		return name.substr(6);
	}

	UpdateState& GetUpdateState(){ return update_state; }
};


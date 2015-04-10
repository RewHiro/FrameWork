#pragma once
#include "Object.h"
#include "Uncopyable.h"

//
//　コンポーネント(抽象クラス)
//

class Component : private Uncopyable
{
	UpdateState update_state = UpdateState::START;
protected:
	bool is_active = true;
	
	//　オブジェクト取得
	const std::shared_ptr<Object>& ObjectFind(const std::string& name);

	//　オブジェクト取得
	const std::pair<OBJECT_MAP_ITR, OBJECT_MAP_ITR>& ObjectFinds(const std::string& name);

	//　コンポーネント取得
	template <class Type>
	const std::shared_ptr<Type>GetComponent()const{
		const std::string& name = typeid(Type).name();
		return std::dynamic_pointer_cast<Type>(object.GetComponentInfo().Find(name.substr(6)));
	}

	template <class Type>
	const std::shared_ptr<Type>GetObjectType()const{
		const std::string& name = typeid(Type).name();
		return std::dynamic_pointer_cast<Type>(ObjectFind(name.substr(6)));
	}

	//　オブジェクト追加
	void ObjectAdd(const std::string& name, const std::shared_ptr<Object>& object);

public:
	Component(Object& object);
	virtual ~Component() = default;

	virtual void Update(){}
	virtual void Start(){}

	//　コンポーネントの名前取得
	virtual std::string Name()const{
		const std::type_info& id = typeid(*this);
		const std::string& name = id.name();
		return name.substr(6);
	}

	UpdateState& GetUpdateState(){ return update_state; }

	Object& object;


};


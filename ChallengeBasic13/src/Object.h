#pragma once
#include "Uncopyable.h"
#include "ComponentTask.h"
#include "ComponentInfo.h"
#include "Transform2D.h"
#include "lib\graph.hpp"
#include  <typeinfo>
#include <stack>

class Transform2D;
class Resource;
class ObjectTask;
class ObjectInfo;
class Object;

using OBJECT_MAP_ITR = std::unordered_multimap<std::string, std::shared_ptr<Object>>::iterator;

//　更新の種類
enum class UpdateState{
	AWAKE,
	START,
	UPDATE,
};

//　オブジェクト(抽象クラス)
class Object : private Uncopyable, public std::enable_shared_from_this<Object>
{
	bool is_delete = false;
	bool is_active = true;
	UpdateState update_state = UpdateState::START;
protected:
	ComponentTask component_task;
	ComponentInfo component_info;
	int sorting_number;
	int frame_count = 0;
	Color color = Color(1, 1, 1);

	//　コンポーネント追加
	void ComponentAdd(std::shared_ptr<Component>component);

	//　更新
	void ComponetStart();
	void ComponetnUpdate();

	//　リソースの取得
	static const std::shared_ptr<Resource> GetResource();

public:
	Transform2D transform2D;
	Transform2D parent_transform2D;
	std::string name;

	Object() = default;
	Object(const Transform2D& transform2D,int sorting_number = 255):
		transform2D(transform2D),
		sorting_number(sorting_number)
	{}

	virtual ~Object() = default;

	virtual void Start(){}
	virtual void Update(){}
	virtual void Draw(){}

	//　使用禁止
	static ObjectInfo& GetObjectInfo();
	//　使用禁止
	static ObjectTask& GetObjectTask();

	//　描画優先順位取得
	int SortingNum()const{ return sorting_number; }

	//　削除するか
	bool IsDelete()const{ return is_delete; }

	//　更新状態を取得
	UpdateState& GetUpdateState(){ return update_state; }

	//　オブジェクト取得
	const std::shared_ptr<Object> ObjectFind(const std::string& name)const;
	//　オブジェクト取得(複数)
	const std::pair<OBJECT_MAP_ITR, OBJECT_MAP_ITR> ObjectFinds(const std::string& name);

	//　コンポーネント取得
	template <class Type>
	const std::shared_ptr<Type>GetComponent()const{
		std::string name = typeid(Type).name();
		return std::dynamic_pointer_cast<Type>(component_info.Find(name.substr(6)));
	}

	template <class Type>
	const std::shared_ptr<Type>GetObjectType()const{
		std::string name = typeid(Type).name();
		return std::dynamic_pointer_cast<Type>(ObjectFind(name.substr(6)));
	}

	//　使用禁止
	const ComponentInfo& GetComponentInfo()const{
		return component_info;
	}
	
	//　オブジェクトの追加
	static void ObjectAdd(const std::string& name, std::shared_ptr<Object>object);

	//　オブジェクトの破壊
	void Destory(std::shared_ptr<Object>object);
};
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

//�@�X�V�̎��
enum class UpdateState{
	AWAKE,
	START,
	UPDATE,
};

//�@�I�u�W�F�N�g(���ۃN���X)
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

	//�@�R���|�[�l���g�ǉ�
	void ComponentAdd(std::shared_ptr<Component>component);

	//�@�X�V
	void ComponetStart();
	void ComponetnUpdate();

	//�@���\�[�X�̎擾
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

	//�@�g�p�֎~
	static ObjectInfo& GetObjectInfo();
	//�@�g�p�֎~
	static ObjectTask& GetObjectTask();

	//�@�`��D�揇�ʎ擾
	int SortingNum()const{ return sorting_number; }

	//�@�폜���邩
	bool IsDelete()const{ return is_delete; }

	//�@�X�V��Ԃ��擾
	UpdateState& GetUpdateState(){ return update_state; }

	//�@�I�u�W�F�N�g�擾
	const std::shared_ptr<Object> ObjectFind(const std::string& name)const;
	//�@�I�u�W�F�N�g�擾(����)
	const std::pair<OBJECT_MAP_ITR, OBJECT_MAP_ITR> ObjectFinds(const std::string& name);

	//�@�R���|�[�l���g�擾
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

	//�@�g�p�֎~
	const ComponentInfo& GetComponentInfo()const{
		return component_info;
	}
	
	//�@�I�u�W�F�N�g�̒ǉ�
	static void ObjectAdd(const std::string& name, std::shared_ptr<Object>object);

	//�@�I�u�W�F�N�g�̔j��
	void Destory(std::shared_ptr<Object>object);
};
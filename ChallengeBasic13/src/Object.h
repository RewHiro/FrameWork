#pragma once
#include "Uncopyable.h"
#include "Transform2D.h"
#include "ComponentTask.h"
class ObjectInfo;
class Object :
	private Uncopyable
{
	std::vector<std::shared_ptr<Component>>components;
protected:
	ComponentTask component_task;

	Transform2D transform2D;
	int sorting_number;

	void ComponentAdd(const std::string& name,std::shared_ptr<Component>component){
		component_task.Add(name, component);
	}
	void ComponetStart(){
		component_task.Start();
	}
	void ComponetnUpdate(){
		component_task.Update();
	}

public:
	Object() = default;
	Object(const Transform2D& transform2D,int sorting_number = 255):
		transform2D(transform2D),
		sorting_number(sorting_number)
	{}
	virtual ~Object() = default;
	virtual void Start(){}
	virtual void Update(){}
	virtual void Draw(){}

	Transform2D GetTransform2D()const{ return transform2D; }

	static ObjectInfo& GetObjectInfo();
	int SortingNum()const{ return sorting_number; }

	const std::shared_ptr<Object> ObjectFind(const std::string& name)const;

	template <class Type>
	const std::shared_ptr<Type>GetComponent(const std::string& name)const{
		return std::dynamic_pointer_cast<Type>(component_task.Find(name));
	}

	template <class Type>
	const std::shared_ptr<Type>GetObjectType(const std::string& name)const{
		return std::dynamic_pointer_cast<Type>(ObjectFind(name));
	}

};
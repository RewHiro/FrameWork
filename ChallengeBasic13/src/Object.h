#pragma once
#include "Uncopyable.h"
#include "Transform2D.h"
#include <memory>
class ObjectInfo;
class Object :
	private Uncopyable
{
protected:
	std::shared_ptr<Object> ObjectFind(const std::string& name)const;
	Transform2D transform2D;
	int sorting_number;
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

};
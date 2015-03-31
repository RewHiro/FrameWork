#pragma once
#include "Uncopyable.h"
#include "Transform2D.h"
#include <memory>
class ObjectInfo;
class Object :
	private Uncopyable
{
	const ObjectInfo& object_info;
protected:
	std::shared_ptr<Object> ObjectFind(const std::string& name)const;
	Transform2D transform2D;
public:
	Object() = default;
	Object(const Transform2D& transform2D,const ObjectInfo& object_info):
		transform2D(transform2D),
		object_info(object_info)
	{}
	virtual ~Object() = default;
	virtual void Start(){}
	virtual void Update(){}
	virtual void Draw(){}

	Transform2D GetTransform2D()const{ return transform2D; }
};
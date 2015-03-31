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
public:
	Object() = default;
	Object(const Transform2D& transform2D):
		transform2D(transform2D)
	{}
	virtual ~Object() = default;
	virtual void Start(){}
	virtual void Update(){}
	virtual void Draw(){}

	Transform2D GetTransform2D()const{ return transform2D; }

	static ObjectInfo& GetObjectInfo();

};
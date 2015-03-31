#pragma once
#include "Uncopyable.h"
#include "Object.h"
#include "ObjectInfo.h"
#include <vector>
class ObjectTask :
	public Uncopyable
{
	std::vector<std::shared_ptr<Object>>objects;
public:
	ObjectTask();
	~ObjectTask();
	void Add(const std::string& name,std::shared_ptr<Object>object){
		objects.emplace_back(object);
		Object::GetObjectInfo().Add(name, object);
	}
	void Start();
	void Update();
	void Draw();
};


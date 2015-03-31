#pragma once
#include "Uncopyable.h"
#include "Object.h"
#include "ObjectInfo.h"
#include <vector>
class ObjectTask :
	public Uncopyable
{
	std::vector<std::shared_ptr<Object>>objects;
	ObjectInfo object_info;
public:
	ObjectTask();

	void Add(const std::string& name,std::shared_ptr<Object>object){
		objects.emplace_back(object);
		object_info.Add(name, object);
	}
	void Start();
	void Update();
	void Draw();

	const ObjectInfo& GetInfo()const{ return object_info; }
};


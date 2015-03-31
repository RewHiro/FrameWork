#pragma once
#include "Uncopyable.h"
#include "Object.h"
#include <unordered_map>
#include <memory>

class ObjectInfo :
	public Uncopyable
{
	using ObjectMap = std::unordered_multimap < std::string, std::shared_ptr<Object> > ;
	ObjectMap object_map;
public:
	ObjectInfo() = default;

	void Add(const std::string& name,std::shared_ptr<Object>object){
		object_map.emplace(name, object);
	}

	std::shared_ptr<Object> Find(const std::string& name)const{
		return object_map.find(name)->second;
	}

	void Clear(){
		object_map.clear();
	}
};


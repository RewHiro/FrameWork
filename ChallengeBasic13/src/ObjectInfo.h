#pragma once
#include "Uncopyable.h"
#include "Object.h"
#include <unordered_map>
#include <memory>

class ObjectInfo :
	private Uncopyable
{
	std::unordered_multimap < std::string, std::shared_ptr<Object> > object_map;
public:
	ObjectInfo() = default;

	void Add(const std::string& name,std::shared_ptr<Object>object){
		object_map.emplace(name, object);
	}

	const std::shared_ptr<Object> Find(const std::string& name)const{
		return object_map.find(name)->second;
	}

	void Erase(std::shared_ptr<Object>object){
		auto objects = object_map.equal_range(object->name);
		auto it = objects.first;
		while(it != objects.second){
			if(it->second->IsDelete()){
				it = object_map.erase(it);
			}
			else ++it;
		}
	}

	void Clear(){
		object_map.clear();
	}
};


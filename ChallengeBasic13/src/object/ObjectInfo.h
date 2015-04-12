#pragma once
#include "utility/Uncopyable.h"
#include "Object.h"

//
//�@�I�u�W�F�N�g�̃f�[�^�Ǘ�
//

class ObjectInfo : private Uncopyable
{
	std::unordered_multimap < std::string, std::shared_ptr<Object> > object_map;
public:
	ObjectInfo() = default;

	//�@�ǉ�
	void Add(const std::string& name,const std::shared_ptr<Object>& object){
		object_map.emplace(name, object);
	}

	//�@����
	const std::shared_ptr<Object>& Find(const std::string& name)const{
		return object_map.find(name)->second;
	}

	//�@����(����)
	const std::pair<OBJECT_MAP_ITR, OBJECT_MAP_ITR>& Finds(const std::string& name){
		return object_map.equal_range(name);
	}

	//�@�폜
	void Erase(const std::shared_ptr<Object>& object){
		auto objects = object_map.equal_range(object->name);
		auto it = objects.first;
		while(it != objects.second){
			if(it->second->IsDelete()){
				it = object_map.erase(it);
			}
			else ++it;
		}
	}

	//�@�f�[�^��S�폜
	void Clear(){
		object_map.clear();
	}
};


#pragma once
#include "Uncopyable.h"
#include "Component.h"
#include <vector>
#include <unordered_map>
#include <memory>

class ComponentTask :
	private Uncopyable
{
	std::vector<std::shared_ptr<Component>>components;
	std::unordered_map<std::string, std::shared_ptr<Component>>component_list;
public:
	ComponentTask();
	void Update(){
		for(auto& component : components){
			component->Update();
		}
	}

	void Add(const std::string& name,std::shared_ptr<Component>component){
		components.emplace_back(component);
		component_list.emplace(name, component);
	}

	std::shared_ptr<Component> Find(const std::string& name)const{
		return component_list.find(name)->second;
	}
};

